/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_TOOLACTION_HXX
#define TEAMCENTER_SOA_CLIENT_TOOLACTION_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/ActionReference.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 */
class TCSOACLIENTMNGD_API ToolAction
{
public:

    virtual ~ToolAction();


    /**
     * @return The action name.
     */
    virtual std::string getName()=0;

     /**
     * @return The list of references.
     */
    virtual std::vector<ActionReference*> getActionReferences()=0;

    /**
     * @return The list of reference names
     */
    virtual std::vector<std::string> getActionReferenceNames()=0;

    /**
     * Get a named Reference.
     * @param name  The name of the desired Reference.
     * @return The  named Reference.
     */
    virtual ActionReference* getActionReference( const std::string& name )=0;

   SOA_CLASS_NEW_OPERATORS

protected:
    ToolAction();

};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

