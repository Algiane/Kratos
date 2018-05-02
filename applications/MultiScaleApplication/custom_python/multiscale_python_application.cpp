/*
==============================================================================
KratosMultiScaleApplication
A library based on:
Kratos
A General Purpose Software for Multi-Physics Finite Element Analysis
Version 1.0 (Released on march 05, 2007).

Copyright 2007
Pooyan Dadvand, Riccardo Rossi, Janosch Stascheit, Felix Nagel
pooyan@cimne.upc.edu
rrossi@cimne.upc.edu
janosch.stascheit@rub.de
nagel@sd.rub.de
- CIMNE (International Center for Numerical Methods in Engineering),
Gran Capita' s/n, 08034 Barcelona, Spain
- Ruhr-University Bochum, Institute for Structural Mechanics, Germany


Permission is hereby granted, free  of charge, to any person obtaining
a  copy  of this  software  and  associated  documentation files  (the
"Software"), to  deal in  the Software without  restriction, including
without limitation  the rights to  use, copy, modify,  merge, publish,
distribute,  sublicense and/or  sell copies  of the  Software,  and to
permit persons to whom the Software  is furnished to do so, subject to
the following condition:

Distribution of this code for  any  commercial purpose  is permissible
ONLY BY DIRECT ARRANGEMENT WITH THE COPYRIGHT OWNERS.

The  above  copyright  notice  and  this permission  notice  shall  be
included in all copies or substantial portions of the Software.

THE  SOFTWARE IS  PROVIDED  "AS  IS", WITHOUT  WARRANTY  OF ANY  KIND,
EXPRESS OR  IMPLIED, INCLUDING  BUT NOT LIMITED  TO THE  WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT  SHALL THE AUTHORS OR COPYRIGHT HOLDERS  BE LIABLE FOR ANY
CLAIM, DAMAGES OR  OTHER LIABILITY, WHETHER IN AN  ACTION OF CONTRACT,
TORT  OR OTHERWISE, ARISING  FROM, OUT  OF OR  IN CONNECTION  WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==============================================================================
*/

//
//   Project Name:        Kratos
//   Last Modified by:    $Author: Massimo Petracca $
//   Date:                $Date: 2013-10-03 19:37:00 $
//   Revision:            $Revision: 1.00 $
//
//

// System includes

#if defined(KRATOS_PYTHON)
// External includes
#include <boost/python.hpp>


// Project includes
#include "includes/define.h"
#include "multiscmesh_moving_application.h"
#include "multiscmesh_moving_application_variables.h"
#include "add_linear_solvers_to_python.h"
#include "add_conditions_to_python.h"
#include "add_strategies_to_python.h"
#include "add_utilities_to_python.h"
#include "add_constitutive_laws_to_python.h"
#include "add_custom_io_to_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

BOOST_PYTHON_MODULE( KratosMultiScaleApplication )
{

    class_ < KratosMultiScaleApplication,
           KratosMultiScaleApplication::Pointer,
           bases<KratosApplication>, boost::noncopyable > ( "KratosMultiScaleApplication" )
           ;

	AddConditionsToPython();
	AddLinearSolversToPython();
	AddStrategiesToPython();
	AddUtilitiesToPython();
	AddConstitutiveLawsToPython();
	AddCustomIOToPython();

    //registering variables in python
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_TEMP_GRAD)

	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_CLAW_MAP_NAME)
	//KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_CLAW_MAP)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_PREDICTION_FLAG)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_DAMAGE_SURFACE_FLAG)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_DAMAGE_SURFACE_LIMIT)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(FLUX_RVE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(HEAT_FLUX_RVE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(HOMOGENIZED_CONDUCTIVITY)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(HOMOGENIZED_CTE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(HOMOGENIZED_CONST_TENS)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(INVERSE_HOMOGENIZED_CONST_TENS)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_NON_LINEAR_FLAG)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(ACTUAL_TAG)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CLAW_LIMIT_DAMAGE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_GENERAL_STRESS_TENSOR)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(EQUIVALENT_DAMAGE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(PREDICTED_STRESS_TENSOR)

	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_1111)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_1122)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_1133)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_2211)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_2222)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_2233)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_3311)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_3322)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCTIVITY_3333)

	KRATOS_REGISTER_IN_PYTHON_VARIABLE(ASPERITIES_CONSTANT)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(BETA_THERMAL_COEFF)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(YOUNG_MAT1)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCT_MAT1)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(POISSON_MAT1)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(YOUNG_MAT2)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONDUCT_MAT2)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(POISSON_MAT2)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(AIR_CONDUCTIVITY)

	KRATOS_REGISTER_IN_PYTHON_VARIABLE(RVE_FULL_TEMPERATURE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(TEMPERATURE_REACTION)

	// for stress prediction
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( LCH_REF_RVE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( EQUIVALENT_DAMAGE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( PREDICTED_STRESS_TENSOR )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_DAMAGE_SURFACE_FLAG )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_PREDICTION_FLAG )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INITIAL_TEMP_GRAD )

	// for rve
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_NON_LINEAR_FLAG )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( RVE_FULL_DISPLACEMENT )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( RVE_FULL_ROTATION )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( RVE_WPC_LAGRANGIAN_DOF )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( RVE_WPC_LAGRANGIAN_REACTION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_WPR_LAGRANGIAN_DOF )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_WPR_LAGRANGIAN_REACTION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_SHELL_WRC_LAGRANGIAN_DOF_X )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_SHELL_WRC_LAGRANGIAN_DOF_REACTION_X )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_SHELL_WRC_LAGRANGIAN_DOF_Y )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RVE_SHELL_WRC_LAGRANGIAN_DOF_REACTION_Y )

	// for lagrange multipliers
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_LAGRANGE )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( ROTATION_LAGRANGE )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( REACTION_DISPLACEMENT_LAGRANGE )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( REACTION_ROTATION_LAGRANGE )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_DOUBLE_LAGRANGE_1 )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( DISPLACEMENT_DOUBLE_LAGRANGE_2 )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( ROTATION_DOUBLE_LAGRANGE_1 )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( ROTATION_DOUBLE_LAGRANGE_2 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DOUBLE_LAGRANGE_SCALE_FACTOR_ALPHA )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DOUBLE_LAGRANGE_SCALE_FACTOR_BETA )

	// for strategies
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( STRATEGY_SOLUTION_STEP_SOLVED )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( STRATEGY_FINALIZE_SOLUTION_STEP_LEVEL )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( CONSTITUTIVE_INTEGRATION_ERROR_CODE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ITERATION_CONVERGENCE_FLAG )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( SUGGESTED_TIME_STEP )

	// for damage constitutive law
	KRATOS_REGISTER_IN_PYTHON_VARIABLE(GAP_INTERFACE)
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( CONVECTION_DEGRADATION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( EXPONENTIAL_DAMAGE )

	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_T_INTERFACE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_C_INTERFACE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_T )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_C )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( FRACTURE_ENERGY_T )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( FRACTURE_ENERGY_C )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_STRESS_T )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_STRESS_C )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRESS_T_0 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRESS_C_0 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRESS_C_P )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRESS_C_M )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRESS_C_R )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRAIN_C_P )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_STRAIN_C_M )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_COMPRESSIVE_LAW_C1 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_COMPRESSIVE_LAW_C2 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_COMPRESSIVE_LAW_C3 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( BIAXIAL_COMPRESSION_MULTIPLIER )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( SHEAR_COMPRESSION_REDUCTION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_TENSILE_SURFACE_S1 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( LUBLINER_SURFACE_PARAM_KC )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( GENRANKINE_SURFACE_PARAM_A )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( GENRANKINE_SURFACE_PARAM_B )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( GENRANKINE_SURFACE_PARAM_C )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_SECANT_MATRIX )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_SECANT_MATRIX )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_MODEL )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DAMAGE_TENSILE_MODEL )

	// for interface constitutive law
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( NORMAL_STIFFNESS )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( TANGENTIAL_STIFFNESS )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( NORMAL_STIFFNESS_COMPRESSION_MULTIPLIER )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( FRACTURE_ENERGY_MODE_I )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( FRACTURE_ENERGY_MODE_II )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( FRACTURE_ENERGY_MODE_III )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( EQUIVALENT_PLASTIC_DISPLACEMENT_JUMP_MODE_I )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( EQUIVALENT_PLASTIC_DISPLACEMENT_JUMP_MODE_II )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( EQUIVALENT_PLASTIC_DISPLACEMENT_JUMP_MODE_III )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INITIAL_COHESION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INITIAL_FRICTION_ANGLE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RESIDUAL_FRICTION_ANGLE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INITIAL_DILATANCY_ANGLE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RESIDUAL_DILATANCY_ANGLE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_TENSILE_LAW_S0 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_S0 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_SP )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_SR )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_EP )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_C1 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_C2 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_C3 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COMPRESSIVE_LAW_C4 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_PLASTIC_DAMAGE_FACTOR_T )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_PLASTIC_DAMAGE_FACTOR_C )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_CAP_VALUE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_TRACTION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_DISPLACEMENT_JUMP )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_COUPLE_TRACTION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_ROTATION_JUMP )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_PLASTIC_DISPLACEMENT_JUMP )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_FUNCTION_VALUE )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( INTERFACE_REDUCED_INTEGRATION )

	// for plots
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_SURFACE_DATA_2D_X )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_SURFACE_DATA_2D_Y )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_SURFACE_DATA_3D_X )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_SURFACE_DATA_3D_Y )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_SURFACE_DATA_3D_Z )

	// for plastic constitutive law
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ISOTROPIC_HARDENING )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( KINEMATIC_HARDENING )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( YIELD_STRESS_INFINITY )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ISOTROPIC_HARDENING_EXPONENT )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( EQUIVALENT_PLASTIC_STRAIN )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( PLASTIC_STRAIN_TENSOR )

	// for stabilized reduced integration
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RI_STABILIZATION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RI_STABILIZATION_RESIDUAL )

	// for enhanced strain elements
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ENH_STRAIN_PARAM_1 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ENH_STRAIN_PARAM_2 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ENH_STRAIN_PARAM_3 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ENH_STRAIN_PARAM_4 )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( ENH_STRAIN_PARAM_5 )

	// misc
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( RANDOM_IMPERFECTION_FACTOR )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( DISCONTINUITY_DIRECTION )
	KRATOS_REGISTER_IN_PYTHON_VARIABLE( LAMBDA_OUTPUT )

	// for shell load conditions
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( SHELL_EDGE_FORCE )
	KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS( SHELL_EDGE_TORQUE )
}


}  // namespace Python.

}  // namespace Kratos.

#endif // KRATOS_PYTHON defined
