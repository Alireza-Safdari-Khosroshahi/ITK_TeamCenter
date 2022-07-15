/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_LOVIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Lov.hxx>





namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {



class LovImpl: public Lov
{
public:

    /**
     *
     * Constructor
     *
     * @param style
     * @param dependProps
     * @param dependStyles
     * @param uid
     * @param specifier
     * @param lovinfo
     */
    LovImpl(
        Lov::Style style,
        const std::vector<std::string>& dependProps,
        const std::vector<Lov::Style>& dependStyles, 
        const std::string& uid,
        int specifier,
        LovInfo* lovinfo
        );
    ~LovImpl();

    SOA_CLASS_NEW_OPERATORS
 
       /**
        * @param    s String to convert to a Style
        * @return   The Style for the given string
        */
     static Style constructSytle( const std::string& s );


    virtual Style getStyle();
    virtual std::vector<std::string> getDependantProperties();
    virtual std::vector<Lov::Style>  getDependantStyles();

    virtual std::string getUid();
    virtual int getSpecifier();
    virtual LovInfo* getLovInfo();


protected:
    const Style                     mStyle;
          std::vector<std::string>  mDependProps;
          std::vector<Lov::Style>   mDependStyles;
    const std::string               mUid;
    const int                       mSpecifier;
          LovInfo*                  mLovInfo;

private:
    LovImpl();      // do not allow use of default

};

}}}//end namespace


#endif

