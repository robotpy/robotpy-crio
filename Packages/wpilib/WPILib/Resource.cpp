/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Resource.h"
#include "Utility.h"
#include "WPIStatus.h"

Resource *Resource::m_resourceList = NULL;

/**
 * Allocate storage for a new instance of Resource.
 * Allocate a bool array of values that will get initialized to indicate that no resources
 * have been allocated yet. The indicies of the resources are 0..size-1.
 */
Resource::Resource(UINT32 elements)
{
	m_size = elements;
	m_isAllocated = new bool[m_size];
	for (UINT32 i=0; i < m_size; i++)
		m_isAllocated[i] = false;
	m_nextResource = m_resourceList;
	m_resourceList = this;
}

/*static*/ void Resource::CreateResourceObject(Resource **r, UINT32 elements)
{
	if (*r == NULL)
		*r = new Resource(elements);
}

/**
 * Delete the allocated array or resources.
 * This happens when the module is unloaded (provided it was statically allocated).
 */
Resource::~Resource()
{
	delete[] m_isAllocated;
}

/**
 * Allocate a resource.
 * When a resource is requested, mark it allocated. In this case, a free resource value
 * within the range is located and returned after it is marked allocated.
 */
UINT32 Resource::Allocate()
{
	for (UINT32 i=0; i < m_size; i++)
	{
		if ( ! m_isAllocated[i])
		{
			m_isAllocated[i] = true;
			return i;
		}
	}
	wpi_fatal(NoAvailablePorts);
	return ~0ul;
}

/**
 * Allocate a specific resource value.
 * The user requests a specific resource value, i.e. channel number and it is verified
 * unallocated, then returned.
 */
UINT32 Resource::Allocate(UINT32 index)
{
	if (index >= m_size)
	{
		wpi_fatal(IndexOutOfRange);
		return ~0ul;
	}
	if ( m_isAllocated[index] )
	{
		wpi_fatal(ResourceAlreadyAllocated);
		return ~0ul;
	}
	m_isAllocated[index] = true;
	return index;
}


/**
 * Free an allocated resource.
 * After a resource is no longer needed, for example a destructor is called for a channel assignment
 * class, Free will release the resource value so it can be reused somewhere else in the program.
 */
void Resource::Free(UINT32 index)
{
	if (index >= m_size)
	{
		wpi_fatal(IndexOutOfRange);
		return;
	}
	if (!m_isAllocated[index])
	{
		wpi_fatal(NotAllocated);
		return;
	}
	m_isAllocated[index] = false;
}
