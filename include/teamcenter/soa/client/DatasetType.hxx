// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_DATASETTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_DATASETTYPE_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/Tool.hxx>
#include <teamcenter/soa/client/Reference.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * Extends the Type interface with data the is specific to Dataset types.
 *
 * @since %Teamcenter Server 9.1
 */
class TCSOACLIENTMNGD_API DatasetType: public virtual Type
{
public:
    virtual ~DatasetType();

    /**
     * The list of Tools that can be used for viewing files associated with this Dataset type.
     * The list may be empty.
     * @return The list of Tools that can be used for viewing files associated with this Dataset type.
     */
    virtual std::vector<Tool*>  getViewTools()=0;

    /**
     * @param name The name of the desired tool
     * @return The named viewing tool.
     */
    virtual Tool* getViewTool( const std::string& name )=0;


    /**
     * The list of Tools that can be used for editing files associated with this Dataset type.
     * This list will always have a least one Tool.
     * @return The list of Tools that can be used for editing files associated with this Dataset type.
     */
    virtual std::vector<Tool*>  getEditTools()=0;

    /**
     * @param name The name of the desired tool
     * @return The named edit tool.
     */
    virtual Tool* getEditTool( const std::string& name )=0;


    /**
     * The list of References associated with this DataSet.
     *
     * @return The list of References associated with this DataSet
     */
    virtual std::vector<Reference*> getReferences() =0;

    /**
     * The list of names of all references associated with this DataSet.
     *
     * @return The list of reference names.
     */
    virtual std::vector<std::string> getReferenceNames()=0;


    /**
     * The named Reference associated with this DataSet.
     * @param name The name of the desired Reference
     *
     * @return The named Reference associated with this DataSet.
     */
    virtual Reference* getReference( const std::string& name )=0;



    SOA_CLASS_NEW_OPERATORS

protected:

};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif


