// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_CLIENT_ERRORCODES_HXX
#define TEAMCENTER_SOA_CLIENT_ERRORCODES_HXX

#include <string>
#include <vector>
#include <map>

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/BaseCode.hxx>





#include <teamcenter/soa/client/SoaClientMngdExports.h>


#define SOA_CLIENT_ERROR_connectionRefused                      500
#define SOA_CLIENT_ERROR_unexpectedResponse                     501
#define SOA_CLIENT_ERROR_unknownHost                            502
#define SOA_CLIENT_ERROR_xmlNotReturned                         503
#define SOA_CLIENT_ERROR_connectionFailed                       504
#define SOA_CLIENT_ERROR_createConnectionFailed                 505
#define SOA_CLIENT_ERROR_loginWithSerializedConnectionFailed    506
#define SOA_CLIENT_ERROR_websealSSONotConfigured                507
#define SOA_CLIENT_ERROR_websealUnexpectedResponse              508
#define SOA_CLIENT_ERROR_websealNoWebsealHeaderResponse         509
#define SOA_CLIENT_ERROR_websealNoPostActionResponse            510
#define SOA_CLIENT_ERROR_websealSsoNotConfigured                511
#define SOA_CLIENT_ERROR_websealCookieNotFound                  512
#define SOA_CLIENT_ERROR_websealNoNewCookies                    513
#define SOA_CLIENT_ERROR_webSealDuplicateCookies                514
#define SOA_CLIENT_ERROR_xmlMarshallError                       515
#define SOA_CLIENT_ERROR_corbaError                             516
#define SOA_CLIENT_ERROR_unhandledInternalServerException       517
#define SOA_CLIENT_ERROR_unhandledCancelException               518
#define SOA_CLIENT_ERROR_fileDoesNotExist                       519
#define SOA_CLIENT_ERROR_fmsRegisterError                       520
#define SOA_CLIENT_ERROR_fmsUploadError                         521
#define SOA_CLIENT_ERROR_fmsDownloadRegister                    522
#define SOA_CLIENT_ERROR_fmsDownloadError                       523
#define SOA_CLIENT_ERROR_propertyNotLoaded                      524
#define SOA_CLIENT_ERROR_invalidPropName                        525
#define SOA_CLIENT_ERROR_failedToCreateCDM                      526
#define SOA_CLIENT_ERROR_objectDoesNotExist                     527
#define SOA_CLIENT_ERROR_failedToCreateCMM                      528
#define SOA_CLIENT_ERROR_failedCDMactiveServer                  529
#define SOA_CLIENT_ERROR_invalidUID                             530
#define SOA_CLIENT_ERROR_missingExpectedDataset                 531
#define SOA_CLIENT_ERROR_invalidCharString                      532
#define SOA_CLIENT_ERROR_invalidDateString                      533
#define SOA_CLIENT_ERROR_cancelCacheDownload                    534
#define SOA_CLIENT_ERROR_policyManager91server                  535
#define SOA_CLIENT_ERROR_policyManager80server                  536
#define SOA_CLIENT_ERROR_policyNotRegistered                    537
#define SOA_CLIENT_ERROR_policyNotDynamic                       538
#define SOA_CLIENT_ERROR_policyInvalidType                      539
#define SOA_CLIENT_ERROR_urlMalformat                           540 
#define SOA_CLIENT_ERROR_operationTimedOut                      541 
#define SOA_CLIENT_ERROR_sslCaCertError                         542 
#define SOA_CLIENT_ERROR_httpOutOfMemory                        543 
#define SOA_CLIENT_ERROR_httpError                              544 
#define SOA_CLIENT_ERROR_xmlParsingError                        545 
#define SOA_CLIENT_ERROR_unexpectedTcResponseXml                546 
#define SOA_CLIENT_ERROR_unexpectedXml                          547 
#define SOA_CLIENT_ERROR_reassignmnetFailedForLincenses         548 
#define SOA_CLIENT_ERROR_reassignmnetFailedForState             549 
#define SOA_CLIENT_ERROR_httpRecoverableError                   550 
#define SOA_CLIENT_ERROR_httpIOSendError                        551 
#define SOA_CLIENT_ERROR_httpIOReceiveError                     552 
#define SOA_CLIENT_ERROR_tccsIOError                            553 
#define SOA_CLIENT_ERROR_tccsConnectionError                    554 
#define SOA_CLIENT_ERROR_tccsProtocolError                      555 
#define SOA_CLIENT_ERROR_notUsingSsoCredentials                 556
#define SOA_CLIENT_ERROR_cryptoFailed                           557
#define SOA_CLIENT_ERROR_faildToUpdatePolicy                    558
#define SOA_CLIENT_ERROR_failedToRegisterTickets                559
#define SOA_CLIENT_ERROR_failedToDownloadFiles                  560
#define SOA_CLIENT_ERROR_failedToDownloadDataset                561
#define SOA_CLIENT_ERROR_failedToInitFSCAndCache                562
#define SOA_CLIENT_ERROR_failedDatasetZip                       563




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 */
class TCSOACLIENTMNGD_API ErrorCodes: public Teamcenter::Soa::Common::BaseCode
{
public:

             ErrorCodes( int code );
    virtual ~ErrorCodes();
    SOA_CLASS_NEW_OPERATORS
    
    /**
     *
     * @return The error code.
     */
    virtual int getCode() const;

    /**
     *
     * @return The error text.
     */
    virtual std::string getText()const;


    /**
     * <UL>
     * <li>  1: Information
     * <li>  2: Warning,
     * <li>  3: Error,
     * <li>  4: UserError;
     *</UL>     
     *
     * @return The severity level.
     */
    virtual Teamcenter::Schemas::Soa::_2006_03::Exceptions::Error::Severity getSeverity() const;

   
private:
    ErrorCodes(  );

    void initializeMessages();
    void initializeMessage( int code, Teamcenter::Schemas::Soa::_2006_03::Exceptions::Error::Severity severity, const std::string& message);

    static std::map<int,std::string>    sMessages;
    static std::map<int,Teamcenter::Schemas::Soa::_2006_03::Exceptions::Error::Severity>            sServerities;

    int mCode;


};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

