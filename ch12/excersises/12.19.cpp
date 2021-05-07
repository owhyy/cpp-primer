#include "12.19.h"
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

ConstStrBlobPtr StrBlob::cbegin() { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() { return ConstStrBlobPtr(*this, data->size()); }
