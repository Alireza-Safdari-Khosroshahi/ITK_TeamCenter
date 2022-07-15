/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_CORE__2012_02_OPERATIONDESCRIPTOR_HXX
#define TEAMCENTER_SERVICES_CORE__2012_02_OPERATIONDESCRIPTOR_HXX

#include <teamcenter/services/core/_2011_06/Operationdescriptor.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2012_02
            {
                class Operationdescriptor;

class TCSOACORESTRONGMNGD_API Operationdescriptor
{
public:

    struct DeepCopyDataInput;
    struct GetDeepCopyDataResponse;

    /**
     * Map contains a list of <name, value> pairs (<code>BusinessObject, vector<DeepCopyData></code>).
     * For each pair, name is the business object and value holds deep copy data for the
     * business object.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Services::Core::_2011_06::Operationdescriptor::DeepCopyData > > DeepCopyInfoMap2;

    /**
     * Input structure for getDeepCopyData operation
     */
    struct DeepCopyDataInput
    {
        /**
         * This is the operation types such as SaveAs,Revise, etc.
         */
        std::string operation;
        /**
         * object reference to get the deepcopydata
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };

    /**
     * getDeepCopyData Response
     */
    struct GetDeepCopyDataResponse
    {
        /**
         * Map of the DeepCopy data
         */
        DeepCopyInfoMap2 deepCopyInfoMap;
        /**
         * Creates a list of Datasets and creates the specified relation type between created
         * Dataset and input container object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation returns information required to perform SaveAs on a Business Object
     * instance.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Client constructs the SaveAs dialog for a Business Object using this operation. The
     * information returned by this operation allows a client to construct the SaveAs dialogs
     * and the DeepCopy panels for user input. Once the user input is received, client can
     * make subsequent invocation to the <code>DataManagement.saveAsObjects</code> operation
     * to execute SaveAs on the object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * saveAsObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param deepCopyDataInput
     *        A list of DeepCopyDataInput structures which contains an object, and operation type.
     *
     * @return
     *         It includes <b>SaveAsInput</b> type name and the <code>DeepCopyData</code> which
     *         is a recursive data structure. The <code>DeepCopyData</code> contains information
     *         about how the secondary objects (related and referenced objects) are to be copied
     *         (reference, copy as object, no copy). The <code>DeepCopyData</code> also contains
     *         SaveAsInputType name for the secondary objects.  If there is an error during the
     *         operation, it will be added to the error stack of the <code>ServiceData</code> as
     *         a partial error
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Operationdescriptor::GetDeepCopyDataResponse getDeepCopyData ( const std::vector< Teamcenter::Services::Core::_2012_02::Operationdescriptor::DeepCopyDataInput >& deepCopyDataInput ) = 0;


protected:
    virtual ~Operationdescriptor() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

