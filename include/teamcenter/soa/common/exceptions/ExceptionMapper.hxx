//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2013
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_EXCEPTIONS_EXCEPTIONMAPPER_HXX
#define TEAMCENTER_SOA_EXCEPTIONS_EXCEPTIONMAPPER_HXX


#include <string>
#include <ostream>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/ConnectionException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/ProtocolException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InvalidCredentialsException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InvalidUserException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/ServiceException.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/SoaException.hxx>

#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Exceptions
            {


/**
 * Maps JETI level exceptions to SOA level exceptions
 */
class TCSOACOMMON_API ExceptionMapper
{

public:
    ExceptionMapper(){};
    ~ExceptionMapper(){};

    /**
     * Maps the JETI level exceptions to the equivalent Web Service level exception.
     * After mapping the exception, the Web Service equivalent is thrown. If an
     * equivalent excpetion does not exist a InternalServerException is thrown. This
     * method will always thrown an exception vs. a normal return.
     *
     * @param ex    The exception to map
     *
     * @throws InvalidCredentialsException
     * @throws InvalidUserException
     * @throws InternalServerException
     * @throws CanceledOperationException
     */
    static void throwSoaException( Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException& ex );

    /**
     * Serialize (XML Document) the given excpetion.
     * The exception is mapped using the throwWebServiceExcetpion
     *
     *
     * @param ex          The exception to serialize.
     * @param outStream   Stream to write the XML document to.

     * @deprecated As of 9.1.2, use writeSoaException( const std::string&, Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException&, std::ostream&  ).
     */
#ifdef WNT
__declspec(deprecated("As of 9.1.2, use writeSoaException( const std::string&, Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException&, std::ostream&  )."))
#endif
    static void writeSoaException( Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException& ex, std::ostream& outStream);

 
    /**
     * Serialize (XML or JSON Document) the given excpetion.
     * The exception is mapped using the throwWebServiceExcetpion
     *
     *
     * @param contentType XML or JSON.
     * @param ex          The exception to serialize.
     * @param outStream   Stream to write the document to.
     */
    static void writeSoaException( const std::string& contentType, Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException& ex, std::ostream& outStream);


    /**
     * Parse an XML string to an exception.
     * The appropriate exception is constructed and populated from the XML document
     * and thrown. This is potentailly used on client to map the XML Response Exception
     * to appropraite objects
     *
     * @param xmlString Source XML document representing an exception
     *
     * @throws InvalidCredentialsException
     * @throws InvalidUserException
     * @throws InternalServerException
     * @throws ServiceException
     */
    static void parseExceptionString( const std::string& xmlString );

    /**
     * Parse an XML string to an exception.
     * This requires a SaxToNodeParser that has already parsed the XML Document
     * otherwise is the same as the same method that takes a string
     *
     * @param parser Source XML document representing an exception
     *
     * @throws InvalidCredentialsException
     * @throws InvalidUserException
     * @throws InternalServerException
     * @throws ServiceException
     */
    static void parseExceptionString( Teamcenter::Soa::Common::Xml::SAXToNodeParser& parser );


    SOA_CLASS_NEW_OPERATORS



private:
    static std::string getTargetNameSpace( const Teamcenter::Schemas::Soa::_2006_03::Exceptions::SoaException& ex );


};

}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
