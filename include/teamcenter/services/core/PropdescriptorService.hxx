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

#ifndef TEAMCENTER_SERVICES_CORE_PROPDESCRIPTORSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_PROPDESCRIPTORSERVICE_HXX

#include <teamcenter/services/core/_2007_06/Propdescriptor.hxx>
#include <teamcenter/services/core/_2008_06/Propdescriptor.hxx>
#include <teamcenter/services/core/_2011_06/Propdescriptor.hxx>



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
            class PropdescriptorService;

/**
 * The <code>PropDescriptor</code> Service is used to obtain metadata for the Create
 * Operation and for properties. Clients can use the metadata information to construct
 * dialogs to be presented to users
 * <br>
 * <br>
 * Use case:
 * <br>
 * <br>
 * Use Case 1: Retrieve a set of Property Descriptors for a list of property names.
 * This is accomplished by invoking the <code>getAttachedPropDescs</code> and <code>getAttachedPropDescs2</code>
 * operations on the service
 * <br>
 * <br>
 * Use Case 2: Retrieve Create Descriptor for a business object and construct Create
 * dialog based on the Descriptor. This is accomplished by invoking the <code>getCreateDesc</code>
 * operation on the service. This is usually followed by a call to the <code>createObjects</code>
 * operation on the <code>DataManagement</code> service to create the object. NOTE:
 * The <code>getCreateDesc</code> operation is deprecated in Teamcenter 10. Create Descriptor
 * information can be obtained from the SOA Client Metamodel instead
 * <br>
 * .
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

class TCSOACORESTRONGMNGD_API PropdescriptorService
    : public Teamcenter::Services::Core::_2007_06::Propdescriptor,
             public Teamcenter::Services::Core::_2008_06::Propdescriptor,
             public Teamcenter::Services::Core::_2011_06::Propdescriptor
{
public:
    static PropdescriptorService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Get the attached property descriptor based on input type name and property names
     * structure.
     *
     * @param inputs
     *        - vector of structure of PropDescInfo with type name and property names vector.
     *
     * @return
     *         AttachedPropDescsResponse - Response structure with Map of input typeName to PropDesc
     *         structure and serviceData
     *
     *
     * @exception ServiceException
     *           
     * @deprecated
     *         As of Teamcenter 9, use the getAttachedPropDescs2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the getAttachedPropDescs2 operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_06::Propdescriptor::AttachedPropDescsResponse getAttachedPropDescs ( const std::vector< Teamcenter::Services::Core::_2007_06::Propdescriptor::PropDescInfo >& inputs ) = 0;

    /**
     * The operation returns information required to create a Business Object. The Create
     * Descriptor (CreateDesc object) includes the metadata information for the properties
     * required when creating a business object  i.e, property is mandatory, property is
     * visible, etc. The CreateDesc is a recursive data structure. The CreateDesc object
     * can also reference CreateDesc on secondary objects through a reference or relation
     * property. For example, the CreateDesc for <b>Item</b> points to CreateDesc on its
     * related secondary objects, <b>ItemRevison</b> and <b>Item Master</b>. The CreateDesc
     * for <b>ItemRevision</b> in turn points to the CreateDesc for <b>ItemRevision Master</b>.
     * <br>
     * <br>
     * NOTE:  The operation will be deprecated as of Teamcenter 10. All the metadata information
     * necessary for the Create operation can be retrieved from the SOA client metamodel.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Get Create Descriptor information for the Create wizard for an object.
     * <br>
     * This call is made to populate the Create dialog for any Business Object. After obtaining
     * the user input on the fields of the create dialog, a call is made to the <code>Teamcenter::Soa::Core::_2008_06::DataManagement::createObjects</code>
     * operation to create the object
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param businessObjectTypeNames
     *        list of business object names for which Create Descriptor is needed.
     *
     * @return
     *         Contains information from the Create Descriptor representing metadata about the properties
     *         relevant to a Create Operation.  For example, property is
     *         <br>
     *         mandatory or property is visible.
     *         <br>
     *         It is a recursive data structure that contains metadata information about any secondary
     *         objects that need to be created
     *         <br>
     *         One of the possible errors returned in the ServiceData is:
     *         <br>
     *         214133  No type was found for the given name
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Core::_2008_06::Propdescriptor::CreateDescResponse getCreateDesc ( const std::vector< std::string >& businessObjectTypeNames ) = 0;

    /**
     * Returns a list of Property Descriptors based on the input structure.  The Property
     * Descriptors contain the Display Name, Description and other information about the
     * input property.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation provides following use case for retrieving a set of Property Descriptors
     * given a type name and list of property names for that type.
     * <br>
     * <br>
     * Use Case 1:<b>Retrieve a set of Property Descriptors for a list of property names.</b>
     * <br>
     * <ul>
     * <li type="disc">Create a new PropDescInfo input structure.
     * </li>
     * <li type="disc">Populate the type name and input list of property names.
     * </li>
     * <li type="disc">Call getAttachedPropDescs2 with the newly created input structure.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Property Layer - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of our PLM platform.  This component defines properties.
     *
     * @param inputs
     *        An input Type Name and a list of property names on the input type.  A Property Descriptor
     *        is returned for each Property Name in the list.
     *
     * @return
     *         A map of InputTypeNameToPropDescOutputMap2, which maps each returned Property Descriptor
     *         to the associated input Type Name.  If any of the input data is invalid, it will
     *         be added to the ServiceData along with the partial error associated with the input
     *         type and property name.
     *         <br>
     *         <br>
     *         Some of the possible error codes added to the ServiceData are listed below.
     *         <br>
     *         <ul>
     *         <li type="disc">214170 The input type name is NULL.
     *         </li>
     *         <li type="disc">214171 The input property is NULL.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           .
     */
    virtual Teamcenter::Services::Core::_2011_06::Propdescriptor::AttachedPropDescsResponse getAttachedPropDescs2 ( const std::vector< Teamcenter::Services::Core::_2007_06::Propdescriptor::PropDescInfo >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PropdescriptorService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

