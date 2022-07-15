//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2010.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

#ifndef SOACPD0WORKSET_ERRORS_H
#define SOACPD0WORKSET_ERRORS_H

#include <common/emh_const.h> 

/*================================================================================================*/
#define SOACPD0WORKSET_ERROR_BASE                                   EMH_SOA_CPD0WORKSET_error_base   

#define SOACPD0WORKSET_internal_error                               ( SOACPD0WORKSET_ERROR_BASE + 1 )
#define SOACPD0WORKSET_expansion_invalid_object                     ( SOACPD0WORKSET_ERROR_BASE + 2 )
#define SOACPD0WORKSET_invalid_page_size                            ( SOACPD0WORKSET_ERROR_BASE + 3 )
#define SOACPD0WORKSET_expansion_unsupported_level                  ( SOACPD0WORKSET_ERROR_BASE + 4 )

#endif
