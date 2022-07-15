/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2018.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**

    @libFnd0Participant_undef.h
    undefines for the Participant library

**/

#include <common/library_indicators.h>


#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef PARTICIPANT_API
#undef PARTICIPANTEXPORT
#undef PARTICIPANTGLOBAL
#undef PARTICIPANTPRIVATE

