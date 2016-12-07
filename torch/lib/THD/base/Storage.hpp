#pragma once

#include "Type.hpp"

#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace thd {

struct Storage {
  Storage() {};
  Storage(const Storage& other) = delete;
  Storage(Storage&& other) = delete;
  virtual ~Storage() {};

  virtual std::size_t elementSize() const = 0;
  virtual std::size_t size() const = 0;
  virtual void* data() = 0;
  virtual const void* data() const = 0;
  virtual Storage& retain() = 0;
  virtual Storage& free() = 0;

  virtual Storage& resize(long new_size) = 0;

  virtual thd::Type type() const = 0;
};

template<typename real>
struct StorageScalarInterface : public Storage {
  using scalar_type = real;
  virtual StorageScalarInterface& fill(scalar_type value) = 0;
};

using FloatStorage = StorageScalarInterface<double>;
using IntStorage = StorageScalarInterface<long long>;

} // namespace thd
