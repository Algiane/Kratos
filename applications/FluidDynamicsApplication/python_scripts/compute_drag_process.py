import KratosMultiphysics
import KratosMultiphysics.FluidDynamicsApplication as KratosFluid


def Factory(settings, model):
    if(type(settings) != KratosMultiphysics.Parameters):
        raise Exception("expected input shall be a Parameters object, encapsulating a json string")

    return ComputeDragProcess(model, settings["Parameters"])


class ComputeDragProcess(KratosMultiphysics.Process):
    def __init__(self, model, settings ):
        """ Auxiliary class to output total flow forces over obstacles in fluid dynamics problems.
        """
        super(ComputeDragProcess,self).__init__()

        default_settings = KratosMultiphysics.Parameters("""
            {
                "mesh_id"                   : 0,
                "model_part_name"           : "please_specify_model_part_name",
                "interval"                  : [0.0, 1e30],
                "write_drag_output_file"    : true,
                "print_drag_to_screen"      : false,
                "print_format"              : ""
            }
            """)

        # Detect "End" as a tag and replace it by a large number
        if(settings.Has("interval")):
            if(settings["interval"][1].IsString()):
                if(settings["interval"][1].GetString() == "End"):
                    settings["interval"][1].SetDouble(1e30)
                else:
                    raise Exception("The second value of interval can be \"End\" or a number, interval currently:"+settings["interval"].PrettyPrintJsonString())

        settings.ValidateAndAssignDefaults(default_settings)

        self.format = settings["print_format"].GetString()

        self.model_part = model[settings["model_part_name"].GetString()]
        self.interval = KratosMultiphysics.Vector(2)
        self.interval[0] = settings["interval"][0].GetDouble()
        self.interval[1] = settings["interval"][1].GetDouble()
        self.print_drag_to_screen = settings["print_drag_to_screen"].GetBool()
        self.write_drag_output_file = settings["write_drag_output_file"].GetBool()

        if (self.model_part.GetCommunicator().MyPID() == 0):
            if (self.write_drag_output_file):
                # Set drag output file name
                self.drag_filename = settings["model_part_name"].GetString() + ".drag"

                # File creation to store the drag evolution
                with open(self.drag_filename, 'w') as file:
                    file.write(settings["model_part_name"].GetString() + " drag \n")
                    file.write("\n")
                    file.write("Time   Fx   Fy   Fz \n")


    def ExecuteFinalizeSolutionStep(self):

        current_time = self.model_part.ProcessInfo[KratosMultiphysics.TIME]

        if((current_time >= self.interval[0]) and  (current_time < self.interval[1])):
            # Compute the drag force
            drag_force = KratosFluid.DragUtilities().CalculateBodyFittedDrag(self.model_part)

            # Write the drag force values
            if (self.model_part.GetCommunicator().MyPID() == 0):
                if (self.print_drag_to_screen):
                    KratosMultiphysics.Logger.PrintInfo("ComputeDragProcess", "DRAG RESULTS:")
                    KratosMultiphysics.Logger.PrintInfo("ComputeDragProcess","Current time: " + str(current_time) + " x-drag: " + format(drag_force[0],self.format) + " y-drag: " + format(drag_force[1],self.format) + " z-drag: " + format(drag_force[2],self.format))

                if (self.write_drag_output_file):
                    with open(self.drag_filename, 'a') as file:
                        file.write(str(current_time)+"   "+format(drag_force[0],self.format)+"   "+format(drag_force[1],self.format)+"   "+format(drag_force[2],self.format)+"\n")
