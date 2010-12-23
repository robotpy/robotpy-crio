// Decribes the information needed to configure a DMA channel.
// Copyright (c) National Instruments 2008.  All Rights Reserved.

#ifndef __tDMAChannelDescriptor_h__
#define __tDMAChannelDescriptor_h__

struct tDMAChannelDescriptor
{
   unsigned int channel;
   unsigned int baseAddress;
   unsigned int depth;
   unsigned int write;
};

#endif // __tDMAChannelDescriptor_h__

