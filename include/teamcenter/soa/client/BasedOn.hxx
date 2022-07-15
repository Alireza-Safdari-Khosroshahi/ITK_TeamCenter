// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_CLIENT_BASEDON_HXX
#define TEAMCENTER_SOA_CLIENT_BASEDON_HXX

#include <string>
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
 * This is an optional element in PropertyDescriptor and indicates if the property is a derived property
 * that is based on another property (called source property).<br>
 *
 * Examples:<br>
 * bl_item_item_id on BOMLine is based on item_id property on Item.<br>
 *
 * It is sometimes necessary to traverse to the based-on property (also called source property)
 * to retrieve information that may not be available on the derived property. For example, for a
 * derived property, the minValue  and maxValue have to be obtained from the source property.
 * Another example is the case of BOMLine properties always being exposed as strings. The actual
 * valueType on the source property may be different.
 */
class TCSOACLIENTMNGD_API BasedOn
{
public:

    virtual ~BasedOn();

    /**
     * @return Name of type that contains the source property.
     */
    virtual std::string getSourceType()=0;

    /**
     * @return Name of source property on which this property is based.
     */
    virtual std::string getSourceProperty() =0;

    SOA_CLASS_NEW_OPERATORS

protected:
    BasedOn();

};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
