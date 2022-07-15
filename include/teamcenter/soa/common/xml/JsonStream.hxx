//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_COMMON_XML_JSONSTREAM_HXX
#define TEAMCENTER_SOA_COMMON_XML_JSONSTREAM_HXX

#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/common/xml/LinkedStreamBuffer.hxx>
#include <teamcenter/soa/common/xml/BaseObject.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {
               namespace Xml
               {
                    class JsonStream;
                    class BaseObject;



class TCSOACOMMON_API JsonStream : public std::iostream
{
public:
     template<class APT> static void writeVectorIfJsonSerializeable( 
                                    const std::vector<Teamcenter::Soa::Common::AutoPtr<APT> >& objs,
                                    const std::string& name,
                                    JsonStream* stream )
    {
        std::vector<Teamcenter::Soa::Common::Xml::BaseObject*> jsonObjs;
        for( size_t i =0; i<objs.size(); i++)
        {
            Teamcenter::Soa::Common::AutoPtr<APT> AutoObj = objs[i];       
            APT* obj = AutoObj.getPtr();

            Teamcenter::Soa::Common::Xml::BaseObject* jsonObj = dynamic_cast<Teamcenter::Soa::Common::Xml::BaseObject*>(obj);
            if(jsonObj != NULL)
            {
                jsonObjs.push_back( jsonObj );
            }
        }
        stream->writeVector( jsonObjs, name );
    }
    template<class APT> static void writeMapIfJsonSerializeable( 
                                    const std::vector<Teamcenter::Soa::Common::AutoPtr<APT> >& objs,
                                    const std::string& name,
                                    JsonStream* stream )
    {
        std::vector<Teamcenter::Soa::Common::Xml::BaseObject*> jsonObjs;
        for( size_t i =0; i<objs.size(); i++)
        {
            Teamcenter::Soa::Common::AutoPtr<APT> AutoObj = objs[i];       
            APT* obj = AutoObj.getPtr();

            Teamcenter::Soa::Common::Xml::BaseObject* jsonObj = dynamic_cast<Teamcenter::Soa::Common::Xml::BaseObject*>(obj);
            if(jsonObj != NULL)
            {
                jsonObjs.push_back( jsonObj );
            }
        }
        stream->writeMap( jsonObjs, name );
    }
    
    template<class PT> static void writeVectorIfJsonSerializeable( 
                                    const std::vector<PT> & objs,
                                    const std::string& name,
                                    JsonStream* stream )
    {
        stream->writeVector( objs, name );
    }
    
    template<class PT> void writeVector( const std::vector<PT>& objs, const std::string& name )
    {
        if(objs.size() > 0)
        {
            writeCommaAndLF();
            mNeedsComma = false;
            mNeedsCR = false;
            *this << mIndent << "\"" << name << "\":";
            *this << "[";
            for( size_t i =0; i<objs.size(); i++)
            {         
                if(i > 0)
                {
                   *this << ",";
                }
                mNeedsComma = false;
                mNeedsCR = false;
                mNeedsIndent = false;
                writeValue( objs[i] );
            }
            *this << "]";
           
        }
    }
    
    static void setTabSize( size_t size );

    JsonStream();
    ~JsonStream();
    SOA_CLASS_NEW_OPERATORS

    void writeObjectOpen();
    void writeObjectOpen( const std::string& qName );
    void writeObjectClose();
    void writeMapOpen();
    void writeMapClose();
    void writeKey      ( const std::string& name  );
    void writeValue    ( const std::string& value );
    void writeValue    ( bool value );
    void writeValue    ( int value );
    void writeValue    ( float value );
    void writeValue    ( double value );
    void writeValue    ( const Teamcenter::Soa::Common::DateTime& value );
    void writeValue    ( const BaseObject& value );

    void writeAttribute( const std::string& name, const std::string& value, bool isSet );
    void writeAttribute( const std::string& name,               bool value, bool isSet );
    void writeAttribute( const std::string& name,               int  value, bool isSet );
    void writeAttribute( const std::string& name,              float value, bool isSet );
    void writeAttribute( const std::string& name,             double value, bool isSet );
    void writeAttribute( const std::string& name, const Teamcenter::Soa::Common::DateTime& value, bool isSet );
      
    void writeObject   ( const std::string& name, const std::string& value, bool isSet  );
    void writeObject   ( const std::string& name, bool value, bool isSet  );
    void writeVector   ( const std::vector<BaseObject*>& objs, const std::string& name );
    void writeVectorMap( const std::vector<BaseObject*>& objs, const std::string& name );

    void writeMap      ( const std::vector<BaseObject*>& objs, const std::string& name );

    std::string toString();
    void toString( std::string& str );




private:


    // Don't allow copy constructors
    JsonStream( const JsonStream& right);
    JsonStream& operator = ( const JsonStream& right);

    
    void pushIndent(  );
    void popIndent(  );
    void writeCommaAndLF();

    static std::vector<std::string> sIndents; 

    LinkedStreamCharBuffer *mBuffer;
    int                        mIndentIndex;
    std::string             mIndent;
    bool                    mNeedsComma;
    bool                    mEmpty;
    bool                    mNeedsCR;
    bool                    mNeedsIndent;
    std::string escapeJsonString(const std::string& input);

};




}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
