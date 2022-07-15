// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2011.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

/**
    @file LateLoad.hxx

    Class to dynamically load shared libraries

*/

#ifndef LATELOAD_HXX
#define LATELOAD_HXX

#include <iostream>

class LateLoad
{
public:

    typedef void *symbolHandle;

    LateLoad(const std::string name);

    virtual ~LateLoad() {}

    // Load the named shared library
    virtual void* load();

    // Get specified symbol form the currently loaded shared library
    void* getSymbol(const char *symName);

    // Unload the currently loaded shared library
    void unload();

protected:
    std::string   libName;
    void          *libHandle;
};

#endif
