// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_ZIPFILE_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_ZIPFILE_HXX

#include <string>
#include <vector>
#include <map>
#include <stdio.h>


#include <teamcenter/soa/common/exceptions/IOException.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>



namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {





class TCSOACOMMON_API ZipException : public Teamcenter::Soa::Common::Exceptions::IOException
{
public:
    ZipException( const std::string& message): IOException(message) {}
    ~ZipException() {}


private:
    ZipException( ) {}


};


class TCSOACOMMON_API RandomAccessFile
{
public:
    /**
     * Create an instance of a random access file.
     *
     * @param filePath The full path to the desired file to open.
     * @param mode     The mode to open the file with. 'r' or 'rb'.
     *
     * @throws IOException If failed to open the named file.
     */
    RandomAccessFile( const std::string& filePath, const std::string& mode );
    ~RandomAccessFile();

    /** 
     * Sets the file-pointer offset, at which the next read or write occurs.
     *
     * @param offset The offset value
     * @param origin Relative location to set the file pointer to.
     *         SEEK_CUR - From the current position.
     *         SEEK_SET - From the begining of the file.
     *         SEEK_END - From the end of the file.
     *
     * @throws IOException If failed set the file-pointer ot the desired location.
     */
    void seek( long offset, int origin );

    /* Returns the current file-pointer offset
     * 
     * @return The current file-pointer offset.
     */
    long tell();

    /* Reads up to length bytes of data from this file into the buffer.
     * The buffer must have space allocated for at least lenght bytes.
     *
     * @param buffer The buffer to read the data into.
     * @param length The maximum number of bytes to read.
     *
     * @return The number of bytes read.
     */
    size_t read     ( void* buffer, size_t length );

    /**
     * Reads a 16 bit integer from the file.
     * 
     * @param value The short to read  the number into.
     * @param label  Text that is included in the exeption if the read fails.
     *
     * @throws IOException If failed to read 2 bytes from the file.
     */
    void   readShort( short* value, const char* label=NULL );

    /**
     * Reads a 32 bit integer from the file.
     * 
     * @param value The int to read  the number into.
     * @param label  Text that is included in the exeption if the read fails.
     *
     * @throws IOException If failed to read 2 bytes from the file.
     */
    void   readInt ( int* value, const char* label=NULL );

private:
    RandomAccessFile();

    FILE* mFILE;
    std::string mFilePath;
};

struct EntryInfo
{
    short       mVersion;
    short       mVersionNeeded;
    short       mFlag;
    short       mCopressionMethod;
    int         mDate;
    int         mCrc;
    int         mCompressedSize;
    int         mUncompresseSize;
    short       mDiskNumStart;
    short       mInternalFA;
    int         mExternalFA;
    std::string mName;
    std::string mComment;
    char        *mExtra;

    EntryInfo():
        mVersion(0),
        mVersionNeeded(0),
        mFlag(0),
        mCopressionMethod(0),
        mDate(0),
        mCrc(0),
        mCompressedSize(0),
        mUncompresseSize(0),
        mDiskNumStart(0),
        mInternalFA(0),
        mExternalFA(0),
        mName(),
        mComment(),
        mExtra(NULL)
    {}
};


class TCSOACOMMON_API ZipEntry
{
public:
    
    ~ZipEntry();
    /**
     * Reads and uncompresses up to length bytes of data from this entry into the buffer.
     * The buffer must have space allocated for at least lenght bytes.
     *
     * @param buffer The buffer to read the data into.
     * @param length The maximum number of bytes of uncompressed data to read.
     *
     * @return The number of uncompressed bytes read, 0 if there is no more data to read.
     *
     * @throws ZipException If failed to read or uncompress the file entry.
     */
    size_t      readFile ( void* buffer, size_t length );
    
    /**
     * The name of the file entry.
     *
     * @return The name of the file entry.
     */
    std::string getName();

    /**
     * The compressed size of the file entry.
     *
     * @return The compressed size of the file entry.
     */
    long        getCompressedSize();

    /**
     * The uncompressed size of the file entry.
     *
     *@return The uncompressed size of the file entry.
     */
    long        getUncompressedSize();

private:
    friend class ZipFile;

    ZipEntry(  );
    ZipEntry( RandomAccessFile* zipFILE );
    void   validateFileHeader( );

    RandomAccessFile*   mZipFILE;
    EntryInfo           mInfo;
    long                mEntryOffset;
    int                 mOffset;
    bool                mValid;
    long                mCurrentDataPosition;
    size_t              mCompressedBytesToRead;
    void*               mZipStream;
    unsigned char*      mInputBuffer;
    int                 mCrcWorking;






};

class TCSOACOMMON_API ZipFile
{

public:

    /**
     * Create an instance of a ZipFile.
     *
     * @param filePath The full path to the desired zip file to open.
     *
     * @throws ZipException If the file contains invalid data.
     */
    ZipFile( const std::string& filePath );
    ~ZipFile(void);

    /**
     * Return the full path of the zip file.
     *
     * @return The full path of the zip file.
     */
    std::string getFileName();

    /**
     * Finds the named entry in the zip file.
     *
     * @param The name of the desired entry.
     *
     * @return The named entry.
     *
     * @throws ZipException If an entry contains invalid data, or the named entry is not found.
     */
    ZipEntry findEntry( const std::string& name );

    /**
     * Returns a list of all entries in the zip file.
     *
     *
     * @return The list of all entries in the zip file.
     *
     * @throws ZipException If an entry contains invalid data.
     */
    std::vector<std::string> getEntryNames( );

    /**
     * Reads and uncompresses up to length bytes of data from the entry into the buffer.
     * The buffer must have space allocated for at least lenght bytes.
     *
     * @param entry The desired entry to read from.
     * @param buffer The buffer to read the data into.
     * @param length The maximum number of bytes of uncompressed data to read.
     *
     * @return The number of uncompressed bytes read, 0 if there is no more data to read.
     *
     * @throws ZipException If failed to read or uncompress the file entry.
     */
    size_t   readItem( ZipEntry& entry, void* buffer, size_t length );

private:
    ZipFile(void);
        
    void open();
    size_t getCentralDirectory();
    size_t readFile (const ZipEntry& entry, void* buffer, size_t length );

    std::string             mSourceFile;
    RandomAccessFile *      mZipFILE;
    long                    mCDPosition;
    short                   mTotalEntries;
    int                     mSizeCD;
    int                     mCDOffset;
    long                    mByteBeforeZip;
    long                    mNextEntryOffset;
    std::map<std::string,long> mEntryIndex;

};

}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

