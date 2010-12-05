#
# bitfield manipulation
#
# http://code.activestate.com/recipes/113799-bit-field-manipulation/ (r1)
# plus fixups for Python 3.x
#

class bf:
    def __init__(self, value=0):
        self._d = value

    def __getitem__(self, index):
        if index is None:
            return self._d
        elif isinstance(index, slice):
            mask = 2**(index.stop - index.start) -1
            return (self._d >> index.start) & mask
        else:
            return (self._d >> index) & 1 

    def __setitem__(self, index, value):
        if index is None:
            self._d = value
            return self._d
        elif isinstance(index, slice):
            mask = 2**(index.stop - index.start) -1
            value = (value & mask) << index.start
            mask = mask << index.start
            self._d = (self._d & ~mask) | value
            return (self._d >> index.start) & mask
        else:
            if value:
                value = 1<<index
            else:
                value = 0
            mask     = 1<<index
            self._d  = (self._d & ~mask) | value

    def __int__(self):
        return self._d

#k = bf()
#k[3:7]=5
#print k[3]
#print k[5]
#k[7]=1
#print k[4:8]
#print int(k)

