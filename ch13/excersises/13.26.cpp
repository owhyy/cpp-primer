#include "13.26.h"
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

ConstStrBlobPtr StrBlob::cbegin() { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() { return ConstStrBlobPtr(*this, data->size()); }

StrBlob::StrBlob(const StrBlob &s)
    : data(std::make_shared<vector<string>>(*s.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &s) {
  data = std::make_shared<vector<string>>(*s.data);
  return *this;
}
