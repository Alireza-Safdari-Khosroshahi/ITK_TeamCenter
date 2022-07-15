/*==================================================================================================

                          Copyright (c) 2020 Siemens Product Lifecycle Management Software Inc.

====================================================================================================
File description:

    Filename: libsanitizer_undef.h
==================================================================================================*/



#if !defined(EXPORTLIBRARY)
#   error EXPORTLIBRARY is not defined
#endif

#undef EXPORTLIBRARY

#if !defined(IPLIB)
#   error IPLIB is not defined
#endif

#undef SANITIZER_API
#undef SANITIZEREXPORT
#undef SANITIZERGLOBAL
#undef SANITIZERPRIVATE





