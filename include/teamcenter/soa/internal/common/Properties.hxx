// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_PROPERTIES_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_PROPERTIES_HXX

#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>



namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
             {
/**
 * This is a low budget implementation of the Java Properties class
 */
class TCSOACOMMON_API Properties 
{
public: 

    Properties( );
    ~Properties( );

    /**
     * Searches for the property with the specified key in this property list. 
     * The method returns NULL if the property is not found. 
     *
     * @param key The property key. 
     * 
     * @return The value in this property list with the specified key value.
     */
    const std::string* getProperty( const std::string& key);

    /**
     * Searches for the property with the specified key in this property list. 
     * The method returns the default value argument if the property is not found. 
     *
     * @param key           The property key. 
     * @param defaultValue  The default value. 
     * 
     * @return The value in this property list with the specified key value.
     */
    std::string  getProperty( const std::string& key, const std::string& defaultValue );

    /**
     * @return all the keys in the property map.
     */
    void getPropertyKeys(std::vector<std::string>& propKeys);

    /**
     * Loads the properies from the given file.
     *
     * @param propFile  File handle to read from.
     */
    void load( FILE * propFile );


   /**
     * Add the propety to the table.
     *
     * @param key           The property key. 
     * @param value         The property value. 
     * 
     */
    void  put( const std::string& key, const std::string& value );


    void erase( const std::string& key );

    SOA_CLASS_NEW_OPERATORS

private:

    typedef std::map< std::string, std::string >    PropertyMap;

    PropertyMap properties;
};



}}}}


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

