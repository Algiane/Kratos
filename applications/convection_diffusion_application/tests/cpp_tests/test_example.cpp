// KRATOS ___ ___  _  ___   __   ___ ___ ___ ___ 
//       / __/ _ \| \| \ \ / /__|   \_ _| __| __|
//      | (_| (_) | .` |\ V /___| |) | || _|| _| 
//       \___\___/|_|\_| \_/    |___/___|_| |_|  APPLICATION
//
//  License: BSD License
//   license: convection_diffusion_application/license.txt
//
//  Main authors:    Vicente Mataix Ferrandiz
//

// System includes
#include <limits>

// External includes

// Project includes
#include "testing/testing.h"


namespace Kratos 
{
    namespace Testing 
    {
        /// Tests
       
        /** Example test
         */
        
        KRATOS_TEST_CASE_IN_SUITE(ExampleTest, KratosConvectionDiffusionFastSuite) 
        {
            constexpr double tolerance = 1e-6;
            
            // Check
            KRATOS_CHECK(true);
        }
    } // namespace Testing
}  // namespace Kratos.

