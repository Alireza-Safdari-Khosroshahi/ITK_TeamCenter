/*HEAD UG_VA_COPY HHH INCLUDE */
/*==============================================================================

                    Copyright 2005 UGS Corp. 
                Unpublished - All rights reserved

================================================================================
File description:

    Default definition of va_copy.

    The va_copy macro is needed in situations where the va_list argument is 
    used more than once, since on some platforms the implementation of 
    va_list/va_arg invalidates any reuse of the va_list type.  Use va_copy
    to make a copy of the va_list argument prior to any call to va_arg.  E.g.

        static int dump( const char *format, ... )
        {
            va_list ap;
            va_start(ap, format);

            va_list qp;
            va_copy(qp,ap);
            vfprintf(ERROR_ask_system_log_stream(), format, qp);
            va_end(qp);

            int len = vprintf(format, ap);
            va_end(ap);

            return len;
        }

    If needed, this header *must* be preceded by inclusion of stdarg.h, since 
    that header may supply a platform specific version of va_copy.

================================================================================
   Date      Name                    Description of Change
09-May-2005  Jack Marr               Use common definition of va_copy
$HISTORY$
==============================================================================*/

#ifndef UG_VA_COPY_H_INCLUDED
#define UG_VA_COPY_H_INCLUDED

#ifndef va_start
#error "Inclusion of ug_va_copy.h must be preceded by inclusion of stdarg.h"
#endif

#ifndef va_copy
#define va_copy(dst, src) ((dst) = (src))
#endif

#endif

