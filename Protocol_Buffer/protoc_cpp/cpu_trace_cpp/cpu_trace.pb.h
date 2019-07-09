// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cpu_trace.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cpu_5ftrace_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cpu_5ftrace_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_cpu_5ftrace_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cpu_5ftrace_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cpu_5ftrace_2eproto;
namespace CPUTrace {
class Instruction;
class InstructionDefaultTypeInternal;
extern InstructionDefaultTypeInternal _Instruction_default_instance_;
}  // namespace CPUTrace
PROTOBUF_NAMESPACE_OPEN
template<> ::CPUTrace::Instruction* Arena::CreateMaybeMessage<::CPUTrace::Instruction>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace CPUTrace {

enum Instruction_Operation : int {
  Instruction_Operation_EXE = 0,
  Instruction_Operation_LOAD = 1,
  Instruction_Operation_STORE = 2,
  Instruction_Operation_Instruction_Operation_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Instruction_Operation_Instruction_Operation_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Instruction_Operation_IsValid(int value);
constexpr Instruction_Operation Instruction_Operation_Operation_MIN = Instruction_Operation_EXE;
constexpr Instruction_Operation Instruction_Operation_Operation_MAX = Instruction_Operation_STORE;
constexpr int Instruction_Operation_Operation_ARRAYSIZE = Instruction_Operation_Operation_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Instruction_Operation_descriptor();
template<typename T>
inline const std::string& Instruction_Operation_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Instruction_Operation>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Instruction_Operation_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Instruction_Operation_descriptor(), enum_t_value);
}
inline bool Instruction_Operation_Parse(
    const std::string& name, Instruction_Operation* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Instruction_Operation>(
    Instruction_Operation_descriptor(), name, value);
}
// ===================================================================

class Instruction :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:CPUTrace.Instruction) */ {
 public:
  Instruction();
  virtual ~Instruction();

  Instruction(const Instruction& from);
  Instruction(Instruction&& from) noexcept
    : Instruction() {
    *this = ::std::move(from);
  }

  inline Instruction& operator=(const Instruction& from) {
    CopyFrom(from);
    return *this;
  }
  inline Instruction& operator=(Instruction&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Instruction& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Instruction* internal_default_instance() {
    return reinterpret_cast<const Instruction*>(
               &_Instruction_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Instruction* other);
  friend void swap(Instruction& a, Instruction& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Instruction* New() const final {
    return CreateMaybeMessage<Instruction>(nullptr);
  }

  Instruction* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Instruction>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Instruction& from);
  void MergeFrom(const Instruction& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Instruction* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "CPUTrace.Instruction";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cpu_5ftrace_2eproto);
    return ::descriptor_table_cpu_5ftrace_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef Instruction_Operation Operation;
  static constexpr Operation EXE =
    Instruction_Operation_EXE;
  static constexpr Operation LOAD =
    Instruction_Operation_LOAD;
  static constexpr Operation STORE =
    Instruction_Operation_STORE;
  static inline bool Operation_IsValid(int value) {
    return Instruction_Operation_IsValid(value);
  }
  static constexpr Operation Operation_MIN =
    Instruction_Operation_Operation_MIN;
  static constexpr Operation Operation_MAX =
    Instruction_Operation_Operation_MAX;
  static constexpr int Operation_ARRAYSIZE =
    Instruction_Operation_Operation_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Operation_descriptor() {
    return Instruction_Operation_descriptor();
  }
  template<typename T>
  static inline const std::string& Operation_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Operation>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Operation_Name.");
    return Instruction_Operation_Name(enum_t_value);
  }
  static inline bool Operation_Parse(const std::string& name,
      Operation* value) {
    return Instruction_Operation_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // uint64 eip = 1;
  void clear_eip();
  static const int kEipFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::uint64 eip() const;
  void set_eip(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // uint64 load_or_store_addr = 3;
  void clear_load_or_store_addr();
  static const int kLoadOrStoreAddrFieldNumber = 3;
  ::PROTOBUF_NAMESPACE_ID::uint64 load_or_store_addr() const;
  void set_load_or_store_addr(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // uint64 size = 4;
  void clear_size();
  static const int kSizeFieldNumber = 4;
  ::PROTOBUF_NAMESPACE_ID::uint64 size() const;
  void set_size(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // .CPUTrace.Instruction.Operation opr = 2;
  void clear_opr();
  static const int kOprFieldNumber = 2;
  ::CPUTrace::Instruction_Operation opr() const;
  void set_opr(::CPUTrace::Instruction_Operation value);

  // @@protoc_insertion_point(class_scope:CPUTrace.Instruction)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::uint64 eip_;
  ::PROTOBUF_NAMESPACE_ID::uint64 load_or_store_addr_;
  ::PROTOBUF_NAMESPACE_ID::uint64 size_;
  int opr_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_cpu_5ftrace_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Instruction

// uint64 eip = 1;
inline void Instruction::clear_eip() {
  eip_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Instruction::eip() const {
  // @@protoc_insertion_point(field_get:CPUTrace.Instruction.eip)
  return eip_;
}
inline void Instruction::set_eip(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  eip_ = value;
  // @@protoc_insertion_point(field_set:CPUTrace.Instruction.eip)
}

// .CPUTrace.Instruction.Operation opr = 2;
inline void Instruction::clear_opr() {
  opr_ = 0;
}
inline ::CPUTrace::Instruction_Operation Instruction::opr() const {
  // @@protoc_insertion_point(field_get:CPUTrace.Instruction.opr)
  return static_cast< ::CPUTrace::Instruction_Operation >(opr_);
}
inline void Instruction::set_opr(::CPUTrace::Instruction_Operation value) {
  
  opr_ = value;
  // @@protoc_insertion_point(field_set:CPUTrace.Instruction.opr)
}

// uint64 load_or_store_addr = 3;
inline void Instruction::clear_load_or_store_addr() {
  load_or_store_addr_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Instruction::load_or_store_addr() const {
  // @@protoc_insertion_point(field_get:CPUTrace.Instruction.load_or_store_addr)
  return load_or_store_addr_;
}
inline void Instruction::set_load_or_store_addr(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  load_or_store_addr_ = value;
  // @@protoc_insertion_point(field_set:CPUTrace.Instruction.load_or_store_addr)
}

// uint64 size = 4;
inline void Instruction::clear_size() {
  size_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Instruction::size() const {
  // @@protoc_insertion_point(field_get:CPUTrace.Instruction.size)
  return size_;
}
inline void Instruction::set_size(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  size_ = value;
  // @@protoc_insertion_point(field_set:CPUTrace.Instruction.size)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace CPUTrace

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::CPUTrace::Instruction_Operation> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CPUTrace::Instruction_Operation>() {
  return ::CPUTrace::Instruction_Operation_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cpu_5ftrace_2eproto
