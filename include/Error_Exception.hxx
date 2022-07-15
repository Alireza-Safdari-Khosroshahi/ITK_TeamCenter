/*HEAD Error_Exception HXX SYSS */
/*===============================================================================

                  Copyright (c) 2003-2004 UGS Corp.
                        Unpublished - All rights reserved

=================================================================================
File description:

Base class for all exception objects that are created and thrown within NX.

=================================================================================
   Date      Name                    Description of Change
NX3
02-Jul-2003  Lavarini
30-Sep-2003  Lavarini                Implement the validate method.
17-Oct-2003  Lavarini                Make methods public for ERROR_FINALLY macros
                                     Make m_bAcknowledged mutable and tighten const
09-Jan-2004  Lavarini                Implement initialize/reset methods
19-Jan-2004  Lavarini                Replace NX namespace with UGS namespace
                                     Use va_list in constructor to remove SM dependence
23-Jan-2004  Lavarini                Change signature of throwException method
25-Aug-2004  Jack Marr               Remove ERROR_CAUGHT_EXCEPTION from ERROR_RECOVER/END for qaz
03-Dec-2004  Lavarini                Convert ERROR functions to macros
                                     Remove qaz changes from 25-Aug-2004
31-Aug-2005  Lavarini                Implement QAZ version of the ERROR macros
$HISTORY$
===============================================================================*/

#ifndef ERROR_EXCEPTION_HXX_INCLUDED
#define ERROR_EXCEPTION_HXX_INCLUDED

#ifdef __lint
#   pragma uginclude only_in_error "error_c_cxx_interface.h","Error_*.hxx",\
                                    "*.cxx","*.cpp";
#endif

#include <exception>

//  <string> must be included to define the std::string type for member variable
//  data of the Exception class.  Unfortunately, a few of our platforms have 
//  not implemented the header file properly.  These platforms are SUN and IBM.
//
//  On SUN, <string> cannot be included because clock_t is used in the header
//  but not completely defined; <time.h> is included here to define clock_t
//  before it is needed by <string>
//
//  On IBM, some classes need forward declarations before they are used somewhere
//  within <string>.  This can be accomplished by defining __OS400__, but since it
//  is unknown what defining this macro implies, the decision was to include
//  <sys/localedef.h> directly which defines the classes needed.
#if defined ( __sun )
#   include <time.h>
#endif

#if defined ( _AIX )
#   include <sys/localedef.h>
#endif

#include <string>

#include <error_datatypes.h>
#include <stdarg.h>
#include <libsyss_exports.h>

#if defined ( WNT )
#pragma warning( push )
#pragma warning( disable : 4275)
#endif

namespace UGS
{
    namespace Error
    {
        class Exception;
    }
}

class SYSSEXPORT UGS::Error::Exception : public std::exception
{

public:

    // Defines the default action taken at the start of a catch block.
    // This method prints a line to the syslog stating where the invoking
    // exception was caught.
    virtual void doDefaultStartAction
    (
        const char *           file_name,   // Name of file where the invoking
                                            // exception was caught.
        int                    line_number, // Line number in file where the
                                            // invoking exception was caught.
        ERROR_recover_type_t   type         // Type of recover block that is
                                            // invoking the method.
    ) const ;

    // Defines the default action taken at the end of a catch block.
    // This specific action taken is determined by the type of recover
    // block
    virtual void doDefaultEndAction
    (
       ERROR_recover_type_t   type         // Type of recover block that is
                                            // invoking the method.
    ) const;

    // Return the data member m_iErrorCode of the invoking exception 
    int askCode ( ) const;

    // Acknowledge the invoking exception.
    // Not every exception can be can be acknowledged, so this base method will
    // generate an Internal exception if it is invoked with checking on.  If a
    // derived exception class can be acknowledged, then that class must implement
    // this method to call Exception::setAcknowledged().
    virtual void acknowledge ( ) const;

    // Re-throw the invoking exception.
    // This member function is only valid within the scope of a catch block as
    // it calls the C++ throw method without any arguments.  With checking on,
    // this method will throw an Internal exception if the invoking exception
    // has already been acknowledged.
    void reThrow ( ) const;

    // Return the data member m_bAcknowledged of the invoking exception 
    logical isAcknowledged ( ) const;

    // Return null-terminated string from the data member m_sFileName of the
    // invoking exception 
    const char *askFileName ( ) const;

    // Return the data member m_iLineNumber of the invoking exception 
    int askLineNumber ( ) const;

    // Return null-terminated string from the data member m_sSyslogText of the
    // invoking exception 
    const char *askSyslogMessage ( ) const;

    // Return a translated error message to output to the User.  This error 
    // message is determined by the error code of the invoking exception.
    const char *askUserMessage ( ) const;

    // Return the exception type of the invoking exception.  As there are really
    // only two types here, this default method returns the value ERROR_ERROR.
    // Redefined in the Escape class to return ERROR_ESCAPE
    virtual ERROR_exception_type_t askType ( ) const;

    // Return static data member pThrownException, which is a copy of the last
    // exception object that was thrown.
    static const Exception * askLastException ( );

    // Check to see if a Callback exception has been saved.
    static logical hasCallbackException ( );

    // Process any saved Callback exception.  If one has been saved, then this
    // method will throw that exception.  If nothing has been saved, then this
    // method will do nothing.
    static void throwCallbackException ( );

    // Set the function pointer to determine if a particular error code is
    // to be suppressed, and return a pointer to the existing function so
    // that it can be restored if required.
    static ERROR_suppression_fn_p_t setSuppressor
    (
        ERROR_suppression_fn_p_t query_function
    );

    // Set the debug handler and the data that it requires.
    static ERROR_debug_handler_t setDebugHandler
    (
        const ERROR_debug_handler_t     &handler
    );

    // Reset the Error Exception mechanism.
    static void reset ( );

    // Set a raise handler.  This function will return the ID of the raise handler
    // so that it can be later canceled.
    static ERROR_raise_handler_id_t setRaiseHandler
    (
        ERROR_raise_handler_fn_p_t  raise_handler
    );

    // Cancel a raise handler.  This function takes the ID returned by setRaiseHandler()
    // to cancel that handler set by that call.
    static void cancelRaiseHandler
    (
        ERROR_raise_handler_id_t    id
    );

    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //  The copy constructor needs to be public in VC7.1 on the WNT platform
    //  to allow the derived exception classes to be caught by the statement:
    //  catch ( UGS::Error::Exception & ERROR_CAUGHT_EXCEPTION ).  I don't
    //  know why this is so.
    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    // Copy constructor
    Exception ( const Exception & right ) throw ( );

    // Throw the invoking exception.  This method makes a copy of the exception
    // before it is thrown.
    // This is a public method to support the ERROR_FINALLY macros
    virtual void throwException ( ) const;

    // Make a copy of the invoking exception.
    // Each instantiable class derived from this base class needs to define
    // this method to be { return ( new Class_name ( *this ) ); }
    // This is a public method to support the ERROR_FINALLY macros
    virtual Exception * makeCopy ( ) const = 0;

    // Destructor
    // This is a public method to support the ERROR_FINALLY macros
    virtual ~Exception ( ) throw ( );

protected:

    // Default constructor
    Exception ( ) throw ( );

    // Normal constructor when the syslog string is already created
    Exception
    (
        const char *        file_name,      // Name of file where the exception
                                            // was thrown.
        int                 line_number,    // Line number in file where exception
                                            // was thrown.
        int                 error_code,     // Error code of exception.
                                            // Can be a negative number to effect
                                            // suppression.
        logical             do_traceback,   // Output a traceback to the syslog for
                                            // this exception
        const char *        syslog_text     // Message that was thrown with the
                                            // exception.
    );

    // Normal constructor when the syslog string needs to be created
    Exception
    (
        const char *        file_name,      // Name of file where the exception
                                            // was thrown.
        int                 line_number,    // Line number in file where exception
                                            // was thrown.
        int                 error_code,     // Error code of exception.
                                            // Can be a negative number to effect
                                            // suppression.
        logical             do_traceback,   // Output a traceback to the syslog for
                                            // this exception
        const char *        control_string, // Format of the message to be thrown
                                            // with the exception.
        va_list             ap              // Arguments of the message
    );

    // Assignment operator
    Exception & operator= ( const Exception & right ) throw ( );

    // Set the data member m_bAcknowledged of the invoking exception to true.
    // This method also sets data member m_bAcknowledged of the static data
    // member pThrownException to true.
    void setAcknowledge ( ) const;

    // Satisfies the requirement of the base std::exception class.  This method
    // should not be used, and that is why it is protected.  Use the public member
    // functions askSyslogMessage() or askUserMessage().
    const char *what ( ) const throw ( );

    // Validates the invoking exception with the pThrownException exception,
    // and uses ASSERT_INTERNAL to raise an exception if these are not the same
    // exception
    void validate ( ) const;

    // Return the data member m_bSuppressed of the invoking exception 
    logical isSuppressed ( ) const;

    // Output a traceback of where the invoking exception was thrown to the
    // System Log file
    void doTraceback
    (
        logical             do_traceback    // Output a traceback to the syslog for
                                            // this exception
    ) const;

private:

    // Value to determine if this error has been acknowledged.  Set to false
    // when object is constructed, the field is set to true within a catch
    // block via a method call.  Not every exception can be acknowledged.
    mutable logical             m_bAcknowledged;

    // This value is set by the constructor to be initially false, but it
    // is really defined in the member function throwException().  This value
    // determines how much information about the exception is placed in the
    // System Log file.
    logical                     m_bSuppressed;

    // The error code asscociated with this exception.
    int                         m_iErrorCode;

    // Name of file where the exception was initially thrown.
    std::string                 m_sFileName;

    // Line number in file where exception was initially thrown.
    int                         m_iLineNumber;

    // Message that was thrown with the exception.  This is the text that gets
    // output to the System Log file.
    std::string                 m_sSyslogText;

    // A pointer to the last exception that was thrown.  This static data member
    // is assigned in the member function throwException() and is accessed via
    // static inquiry member functions.
    static const Exception *    pThrownException;

    // A pointer to the last exception that the member function
    // doCallbackEndAction() was invoked on.  This static data member is assigned
    // in the member function doCallbackEndAction() and thrown in the static
    // member function throwCallbackException().
    static const Exception *    pCallbackException;

    // A flag to determine if the static data member pCallbackException needs to
    // be thrown.  This variable is set to true in the member function
    // doCallbackEndAction().  If is value is true, then the static member
    // function throwCallbackException() will reset the variable to false and
    // throw the exception pCallbackException.
    static logical              bCallbackException;

    // A pointer to a function to determine if an exception with a particular
    // error code is to be suppressed.
    static ERROR_suppression_fn_p_t
                                pfnAskErrorSuppression;

    // The debug handler.  If present, the debug handler function will be
    // excecuted in throwException() prior to the exception being thrown
    static ERROR_debug_handler_t
                                tDebugHandler;

    // Do the actual throw.
    // Each instantiable class derived from this base class needs to define
    // this method to be { throw (*this); }
    virtual void doThrow ( ) const = 0;

    // Print a leader line to the System Log file regarding information about the
    // invoking exception.
    void printLeaderLine ( ) const;

    // Return an exception-specific text string regarding the invoking exception.
    virtual const char * askLeaderLine ( ) const = 0;

    // Defines the action taken at the end of the ERROR_RECOVER catch block.
    // This default member function simply throws the exception to the next
    // catch block.  To get a different behavior, a derived class will need
    // to redefine this member function.
    virtual void doErrorEndAction ( ) const;

    // Defines the action taken at the end of the ERROR_ESCAPE_RECOVER catch block.
    // This default member function is identical to Exception::doErrorEndAction().
    virtual void doEscapeEndAction ( ) const;

    // Defines the action taken within a CALLBACK_END macro.
    // This method will copy the invoking exception to the static data member
    // pCallbackException and set the static data member bCallbackException to
    // true.
    virtual void doCallbackEndAction ( ) const;

    // Initialize the exception.  This is required to perform common tasks for
    // the excepion that has multiple constructors
    void initialize ( );
};

#if defined ( WNT )
#pragma warning( pop ) 
#endif
// To facilitate the catching of a particular object, this macro is implemented
// to define a variable name that can be used in all error handling macros and
// can be used in application code within the context of a recover block.
#define ERROR_CAUGHT_EXCEPTION    _exc

// The following three macros are the default versions of those macros that
// application code uses for error handling.  These macros must not be placed
// directly in application code; this macros are strictly used to provide a
// basis for other macros defined in other header files.
// <DJL> 31-Aug-2005
// Implement _lint versions of these macros so as to generate QAZ warning [#429]
// if a return statement is located within a ERROR_PROTECT or ERROR_RECOVER block
#ifdef _lint
#   define ERROR_DEFAULT_PROTECT \
        try\
        {\
            char * INVALID_RETURN_FROM_ERROR_PROTECT_BLOCK = new char;

#   define ERROR_DEFAULT_RECOVER(type) \
            /*NOTREACHED*/delete INVALID_RETURN_FROM_ERROR_PROTECT_BLOCK;\
        }\
        catch ( const UGS::Error::Exception & ERROR_CAUGHT_EXCEPTION )\
        {\
            char * INVALID_RETURN_FROM_ERROR_RECOVER_BLOCK = new char;\

#   define ERROR_DEFAULT_END(type) \
            /*NOTREACHED*/delete INVALID_RETURN_FROM_ERROR_RECOVER_BLOCK;\
        }
#else   // _lint
#   define ERROR_DEFAULT_PROTECT \
        try\
        {

#   define ERROR_DEFAULT_RECOVER(type) \
        }\
        catch ( const UGS::Error::Exception & ERROR_CAUGHT_EXCEPTION )\
        {\
            ERROR_CAUGHT_EXCEPTION.doDefaultStartAction ( ERROR_line, type );

#   define ERROR_DEFAULT_END(type) \
            ERROR_CAUGHT_EXCEPTION.doDefaultEndAction ( type );\
        }
#endif  // _lint

// The following macros used to be functions to either reraise an error, or make
// inquiries concerning an error.  In the case of the reraise function, this ONLY
// works if done within a catch block, so it is defined here as a macro to insure
// that it is only used in that context.  The other inquiry functions are defined
// as macros because it just makes sense to make inquiries of an exception when
// at the time that the exception is caught.
#define ERROR_ask_failure_code      ERROR_CAUGHT_EXCEPTION.askCode

#define ERROR_reraise               ERROR_CAUGHT_EXCEPTION.reThrow

#define ERROR_ask_exception_type    ERROR_CAUGHT_EXCEPTION.askType

#define ERROR_acknowledge_handled   ERROR_CAUGHT_EXCEPTION.acknowledge

//extern SYSSEXPORT const char *ERROR_ask_file_name ( void );
#define ERROR_ask_file_name         ERROR_CAUGHT_EXCEPTION.askFileName

//extern SYSSEXPORT int ERROR_ask_line_number ( void );
#define ERROR_ask_line_number       ERROR_CAUGHT_EXCEPTION.askLineNumber

//extern SYSSEXPORT const char *ERROR_ask_syslog_message ( void );
#define ERROR_ask_syslog_message    ERROR_CAUGHT_EXCEPTION.askSyslogMessage

#undef EXPORTLIBRARY

#endif  /* ERROR_EXCEPTION_HXX_INCLUDED */
