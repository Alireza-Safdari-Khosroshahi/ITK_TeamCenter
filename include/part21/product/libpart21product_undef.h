/*================================================================================

                           Copyright 2013.
              Siemens Product Lifecycle Management Software Inc.
                        All Rights Reserved.
 ==============================================================================*/

/*
    File Description:

    The header file that undefines the export symbols for the PART21PRODUCT library
 */

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef PART21PRODUCT_API
#undef PART21PRODUCTEXPORT
#undef PART21PRODUCTGLOBAL
#undef PART21PRODUCTPRIVATE

