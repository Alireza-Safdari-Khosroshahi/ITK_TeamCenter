/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_FCCPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_FCCPROXY_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**
 * FccProxy class
 * A class that exposes selected elements of the internal FCC API to SOA clients.
 */
class TCSOACLIENTMNGD_API FccProxy
{
public:

    /** Map of FMS tickets to ifails (error result codes). */
    typedef std::map< std::string, int > TicketFailureMap;

    /** Map of ticket (as key) to path (as value - relative or absolute) */
    typedef std::map< std::string, std::string > TicketPathMap;

    /**
     * Downloads PLM files into the FCC cache, and returns the cache file name.
     * This method is not applicable to non-cacheable files, such as transient volume files.
     * Use downloadFilesToLocation(const TicketPathMap&, const std::string&, TicketFailureMap&) for non-cacheable files.
     *
     * @param tickets INPUT A vector of FMS tickets.
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     * @param filePaths OUTPUT An initially empty vector of file paths.
     *  This method will populate the vector with fully qualified paths to the downloaded files.
     *  The index of the path in the result vector matches the index of the input <code>tickets</code>.
     *  The returned file paths are provided in constructor-selected encoding.
     *  The returned vector may contain NULL values as placeholders for failed downloads.
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in constructor-selected encoding.
     *  If all downloads succeed, this map may be empty upon return.
     */
    void downloadFiles( const std::vector<std::string>& tickets,
                        std::vector<std::string>& filePaths,
                        TicketFailureMap& failedTickets )const;

    /**
     * Downloads PLM files into client-specified filenames.
     *
     * @param ticketsWithPaths: INPUT A mapping of FMS tickets (keys) to destination file paths (values).
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     *  This map must contain paths (values) in constructor-selected encoding.
     * @param directory INPUT A destination directory name in constructor-selected encoding.
     *  May be NULL if ticketsWithPaths contains fully qualified file paths.
     *  An empty string here implies the 'root' directory path (e.g., '/' on Unix).
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in constructor-selected encoding.
     *  If all downloads succeed, this map may be empty upon return.
     */
    void downloadFilesToLocation( const TicketPathMap& ticketsWithPaths,
                                  const std::string& directory,
                                  TicketFailureMap& failedTickets ) const ;

    /**
     * Uploads local client files to a PLM volume.
     *
     * @param ticketsWithPaths: INPUT A mapping of FMS tickets (keys) to source file paths (values).
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     *  This map must contain paths (values) in constructor-selected encoding.
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in constructor-selected encoding.
     *  If all uploads succeed, this map may be empty upon return.
     */
    void uploadFiles( const TicketPathMap& ticketsWithPaths,
                      TicketFailureMap& failedTickets ) const ;

    /**
     * Constructs the FccProxy class to implement default native encoding.
     * Equivalent to FccProxy(false).
     */
    FccProxy();

    /**
     * Constructs the FccProxy class to implement either UTF-8 or default native encoding.
     *
     * @param bIsUTF8 INPUT A flag which selects the encoding semantics.
     * If <code>bIsUTF8</code> is true, initializes the FccProxy class to implement UTF-8 encoding.
     * If <code>bIsUTF8</code> is false, initializes the FccProxy class to implement default native encoding.
     */
    FccProxy(bool bIsUTF8);

    /** Destructs the FccProxy class. */
    ~FccProxy();

    SOA_CLASS_NEW_OPERATORS

    /** Initilaization flag. */
    bool m_isInited;

private:
    /** Initializer */
    void init();
    /** Native encoding initializer. */
    void initNative();
    /** UTF-8 encoding initializer. */
    void initUTF8();

    /** Encoding selector flag. */
    bool m_bIsUTF8;

    /**
     * Downloads PLM files into the FCC cache, and returns the cache file names in default native encoding.
     * This method is not applicable to non-cacheable files, such as transient volume files.
     * Use downloadFilesToLocationNative(const TicketPathMap&, const std::string&, TicketFailureMap&) for non-cacheable files.
     *
     * @param tickets INPUT A vector of FMS tickets.
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     * @param filePaths OUTPUT An initially empty vector of file paths.
     *  This method will populate the vector with fully qualified paths to the downloaded files.
     *  The index of the path in the result vector matches the index of the input <code>tickets</code>.
     *  The returned file paths are provided in default native encoding.
     *  The returned vector may contain NULL values for failed downloads.
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in default native encoding.
     *  If all downloads succeed, this map may be empty upon return.
     */
    void downloadFilesNative( const std::vector<std::string>& tickets,
                        std::vector<std::string>& nativeFilePaths,
                        TicketFailureMap& failedNativeTickets )const;

    /**
     * Downloads PLM files into the FCC cache, and returns the cache file names in UTF-8 encoding.
     * This method is not applicable to non-cacheable files, such as transient volume files.
     * Use downloadFilesToLocationUTF8(const TicketPathMap&, const std::string&, TicketFailureMap&) for non-cacheable files.
     *
     * @param tickets INPUT A vector of FMS tickets.
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     * @param filePaths OUTPUT An initially empty vector of file paths.
     *  This method will populate the vector with fully qualified paths to the downloaded files.
     *  The index of the path in the result vector matches the index of the input <code>tickets</code>.
     *  The returned file paths are provided in UTF-8 encoding.
     *  The returned vector may contain NULL values for failed downloads.
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in UTF-8 encoding.
     *  If all downloads succeed, this map may be empty upon return.
     */
    void downloadFilesUTF8( const std::vector<std::string>& tickets,
                        std::vector<std::string>& UTF8FilePaths,
                        TicketFailureMap& failedUTF8Tickets )const;

    /**
     * Downloads PLM files into client-specified filenames in default native encoding.
     *
     * @param ticketsWithPaths: INPUT A mapping of FMS tickets (keys) to destination file paths (values).
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     *  This map must contain paths (values) in default native encoding.
     * @param directory INPUT A destination directory name in default native encoding.
     *  May be NULL if ticketsWithPaths contains fully qualified file paths.
     *  An empty string here implies the 'root' directory path (e.g., '/' on Unix).
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in default native encoding.
     *  If all downloads succeed, this map may be empty upon return.
     */
    void downloadFilesToLocationNative( const TicketPathMap& ticketsWithNativePaths,
                                  const std::string& nativeDirectory,
                                  TicketFailureMap& failedNativeTickets ) const ;

    /**
     * Downloads PLM files into client-specified filenames in UTF-8 encoding.
     *
     * @param ticketsWithPaths: INPUT A mapping of FMS tickets (keys) to destination file paths (values).
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     *  This map must contain paths (values) in UTF-8 encoding.
     * @param directory INPUT A destination directory name in constructor-selected encoding.
     *  May be NULL if ticketsWithPaths contains fully qualified file paths.
     *  An empty string here implies the 'root' directory path (e.g., '/' on Unix).
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in UTF-8 encoding.
     *  If all downloads succeed, this map may be empty upon return.
     */
    void downloadFilesToLocationUTF8( const TicketPathMap& ticketsWithUTF8Paths,
                                  const std::string& UTF8Directory,
                                  TicketFailureMap& failedUTF8Tickets ) const ;

    /**
     * Uploads local client files from default native paths to a PLM volume.
     *
     * @param ticketsWithPaths: INPUT A mapping of FMS tickets (keys) to source file paths (values).
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     *  This map must contain paths (values) in default native encoding.
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in default native encoding.
     *  If all uploads succeed, this map may be empty upon return.
     */
    void uploadFilesNative( const TicketPathMap& ticketsWithNativePaths,
                      TicketFailureMap& failedNativeTickets ) const ;

    /**
     * Uploads local client files from UTF-8 paths to a PLM volume.
     *
     * @param ticketsWithPaths: INPUT A mapping of FMS tickets (keys) to source file paths (values).
     *  FMS tickets are always in URL-encoded UTF-8 encoding.  Do not re-encode FMS tickets.
     *  This map must contain paths (values) in UTF-8 encoding.
     * @param failedTickets OUTPUT An initially empty mapping of failed tickets to ifails (error result codes).
     *  This method will log error strings in UTF-8 encoding.
     *  If all uploads succeed, this map may be empty upon return.
     */
    void uploadFilesUTF8( const TicketPathMap& ticketsWithUTF8Paths,
                      TicketFailureMap& failedUTF8Tickets ) const ;

};

/** FccProxy Exception class */
class  TCSOACLIENTMNGD_API FccException
{
public:
    /**
     * Constructs an FccException.
     *
     * @param failcode INPUT The 'ifail', or failure code.
     * @param msg INPUT The error text, or description of the unexpected condition encountered.
     *  Error text may be in default native encoding or UTF-8, depending on the context.
     */
    explicit FccException( int failcode = 0, const std::string& msg="" );
    /** Destructs an FccException. */
    ~FccException();

    /** @return The ifail, or error code. */
    int failCode() const;

    /**
     * An error text message or description of the FccException.
     *  Error text may be in default native encoding or UTF-8, depending on the context.
     */
    const std::string& msg() const;

private:
    /** The ifail, or error code. */
    int m_failCode;
    /**
     * The error text or description.
     *  Error text may be in default native encoding or UTF-8, depending on the context.
     */
    std::string m_msg;
};

}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
