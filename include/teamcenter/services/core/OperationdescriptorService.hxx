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

#ifndef TEAMCENTER_SERVICES_CORE_OPERATIONDESCRIPTORSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_OPERATIONDESCRIPTORSERVICE_HXX

#include <teamcenter/services/core/_2011_06/Operationdescriptor.hxx>
#include <teamcenter/services/core/_2012_02/Operationdescriptor.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class OperationdescriptorService;

/**
 * The <code>OperationDescriptor</code> service is used to obtain the metadata for operations
 * like <code>SaveAs</code>. Clients can use the metadata information to construct the
 * dialogs to be presented to the end user for the operations.
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API OperationdescriptorService
    : public Teamcenter::Services::Core::_2011_06::Operationdescriptor,
             public Teamcenter::Services::Core::_2012_02::Operationdescriptor
{
public:
    static OperationdescriptorService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation returns information required to save a business object. The <code>SaveAsDescriptor</code>
     * includes the metadata information for the properties required when saving a business
     * object, i.e., the property is mandatory, the property is visible, if value is to
     * be copied from original object, etc.  The <code>SaveAsDescriptor</code> also includes
     * the <code>DeepCopyData</code> which is a recursive data structure. The <code>DeepCopyData</code>
     * contains information about how the secondary objects (related and referenced objects)
     * are to be copied (reference, copy as object, no copy).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Get SaveAsDescriptor for the SaveAs wizard</b>
     * <br>
     * Client constructs the SaveAs dialog for a Business Object using this operation. The
     * information returned by this operation allows a client to construct the SaveAs dialogs
     * and DeepCopy panels for user input. Once the user input is received, client can make
     * subsequent invocation to the <code>DataManagement.saveAsObjects</code> operation
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
     * @param targetObjects
     *        Set of objects for which the SaveAs Descriptor is needed.
     *
     * @return
     *         This is metadata information about the properties relevant to a Save As operation
     *         i.e, the property is mandatory, the property is visible, if value is to be copied
     *         from original object, etc. It also includes the <code>DeepCopyData</code> which is
     *         a recursive data structure. The <code>DeepCopyData</code> contains information about
     *         how the secondary objects (related and referenced objects) are to be copied (reference,
     *         copy as object, no copy).
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2011_06::Operationdescriptor::SaveAsDescResponse getSaveAsDesc ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& targetObjects ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("OperationdescriptorService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

