// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensor_slice.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "tensor_slice.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace tensorflow {

namespace {

const ::google::protobuf::Descriptor* TensorSliceProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TensorSliceProto_reflection_ = NULL;
const ::google::protobuf::Descriptor* TensorSliceProto_Extent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  TensorSliceProto_Extent_reflection_ = NULL;
struct TensorSliceProto_ExtentOneofInstance {
  ::google::protobuf::int64 length_;
}* TensorSliceProto_Extent_default_oneof_instance_ = NULL;

}  // namespace


void protobuf_AssignDesc_tensor_5fslice_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_tensor_5fslice_2eproto() {
  protobuf_AddDesc_tensor_5fslice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "tensor_slice.proto");
  GOOGLE_CHECK(file != NULL);
  TensorSliceProto_descriptor_ = file->message_type(0);
  static const int TensorSliceProto_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TensorSliceProto, extent_),
  };
  TensorSliceProto_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      TensorSliceProto_descriptor_,
      TensorSliceProto::internal_default_instance(),
      TensorSliceProto_offsets_,
      -1,
      -1,
      -1,
      sizeof(TensorSliceProto),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TensorSliceProto, _internal_metadata_));
  TensorSliceProto_Extent_descriptor_ = TensorSliceProto_descriptor_->nested_type(0);
  static const int TensorSliceProto_Extent_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TensorSliceProto_Extent, start_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(TensorSliceProto_Extent_default_oneof_instance_, length_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TensorSliceProto_Extent, has_length_),
  };
  TensorSliceProto_Extent_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      TensorSliceProto_Extent_descriptor_,
      TensorSliceProto_Extent::internal_default_instance(),
      TensorSliceProto_Extent_offsets_,
      -1,
      -1,
      -1,
      TensorSliceProto_Extent_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TensorSliceProto_Extent, _oneof_case_[0]),
      sizeof(TensorSliceProto_Extent),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TensorSliceProto_Extent, _internal_metadata_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_tensor_5fslice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      TensorSliceProto_descriptor_, TensorSliceProto::internal_default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      TensorSliceProto_Extent_descriptor_, TensorSliceProto_Extent::internal_default_instance());
}

}  // namespace

void protobuf_ShutdownFile_tensor_5fslice_2eproto() {
  TensorSliceProto_default_instance_.Shutdown();
  delete TensorSliceProto_reflection_;
  TensorSliceProto_Extent_default_instance_.Shutdown();
  delete TensorSliceProto_Extent_default_oneof_instance_;
  delete TensorSliceProto_Extent_reflection_;
}

void protobuf_InitDefaults_tensor_5fslice_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  TensorSliceProto_default_instance_.DefaultConstruct();
  TensorSliceProto_Extent_default_instance_.DefaultConstruct();
  TensorSliceProto_Extent_default_oneof_instance_ = new TensorSliceProto_ExtentOneofInstance();
  TensorSliceProto_default_instance_.get_mutable()->InitAsDefaultInstance();
  TensorSliceProto_Extent_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_tensor_5fslice_2eproto_once_);
void protobuf_InitDefaults_tensor_5fslice_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_tensor_5fslice_2eproto_once_,
                 &protobuf_InitDefaults_tensor_5fslice_2eproto_impl);
}
void protobuf_AddDesc_tensor_5fslice_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_tensor_5fslice_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022tensor_slice.proto\022\ntensorflow\"\200\001\n\020Ten"
    "sorSliceProto\0223\n\006extent\030\001 \003(\0132#.tensorfl"
    "ow.TensorSliceProto.Extent\0327\n\006Extent\022\r\n\005"
    "start\030\001 \001(\003\022\020\n\006length\030\002 \001(\003H\000B\014\n\nhas_len"
    "gthB2\n\030org.tensorflow.frameworkB\021TensorS"
    "liceProtosP\001\370\001\001b\006proto3", 223);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "tensor_slice.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_tensor_5fslice_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_tensor_5fslice_2eproto_once_);
void protobuf_AddDesc_tensor_5fslice_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_tensor_5fslice_2eproto_once_,
                 &protobuf_AddDesc_tensor_5fslice_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_tensor_5fslice_2eproto {
  StaticDescriptorInitializer_tensor_5fslice_2eproto() {
    protobuf_AddDesc_tensor_5fslice_2eproto();
  }
} static_descriptor_initializer_tensor_5fslice_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TensorSliceProto_Extent::kStartFieldNumber;
const int TensorSliceProto_Extent::kLengthFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TensorSliceProto_Extent::TensorSliceProto_Extent()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_tensor_5fslice_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.TensorSliceProto.Extent)
}
TensorSliceProto_Extent::TensorSliceProto_Extent(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_InitDefaults_tensor_5fslice_2eproto();
#endif  // GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.TensorSliceProto.Extent)
}

void TensorSliceProto_Extent::InitAsDefaultInstance() {
  TensorSliceProto_Extent_default_oneof_instance_->length_ = GOOGLE_LONGLONG(0);
}

TensorSliceProto_Extent::TensorSliceProto_Extent(const TensorSliceProto_Extent& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tensorflow.TensorSliceProto.Extent)
}

void TensorSliceProto_Extent::SharedCtor() {
  start_ = GOOGLE_LONGLONG(0);
  clear_has_has_length();
  _cached_size_ = 0;
}

TensorSliceProto_Extent::~TensorSliceProto_Extent() {
  // @@protoc_insertion_point(destructor:tensorflow.TensorSliceProto.Extent)
  SharedDtor();
}

void TensorSliceProto_Extent::SharedDtor() {
  ::google::protobuf::Arena* arena = GetArenaNoVirtual();
  if (arena != NULL) {
    return;
  }

  if (has_has_length()) {
    clear_has_length();
  }
}

void TensorSliceProto_Extent::ArenaDtor(void* object) {
  TensorSliceProto_Extent* _this = reinterpret_cast< TensorSliceProto_Extent* >(object);
  (void)_this;
}
void TensorSliceProto_Extent::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void TensorSliceProto_Extent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TensorSliceProto_Extent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TensorSliceProto_Extent_descriptor_;
}

const TensorSliceProto_Extent& TensorSliceProto_Extent::default_instance() {
  protobuf_InitDefaults_tensor_5fslice_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<TensorSliceProto_Extent> TensorSliceProto_Extent_default_instance_;

TensorSliceProto_Extent* TensorSliceProto_Extent::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<TensorSliceProto_Extent>(arena);
}

void TensorSliceProto_Extent::clear_has_length() {
// @@protoc_insertion_point(one_of_clear_start:tensorflow.TensorSliceProto.Extent)
  switch (has_length_case()) {
    case kLength: {
      // No need to clear
      break;
    }
    case HAS_LENGTH_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = HAS_LENGTH_NOT_SET;
}


void TensorSliceProto_Extent::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.TensorSliceProto.Extent)
  start_ = GOOGLE_LONGLONG(0);
  clear_has_length();
}

bool TensorSliceProto_Extent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.TensorSliceProto.Extent)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 start = 1;
      case 1: {
        if (tag == 8) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &start_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_length;
        break;
      }

      // optional int64 length = 2;
      case 2: {
        if (tag == 16) {
         parse_length:
          clear_has_length();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &has_length_.length_)));
          set_has_length();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.TensorSliceProto.Extent)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.TensorSliceProto.Extent)
  return false;
#undef DO_
}

void TensorSliceProto_Extent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.TensorSliceProto.Extent)
  // optional int64 start = 1;
  if (this->start() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->start(), output);
  }

  // optional int64 length = 2;
  if (has_length()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->length(), output);
  }

  // @@protoc_insertion_point(serialize_end:tensorflow.TensorSliceProto.Extent)
}

::google::protobuf::uint8* TensorSliceProto_Extent::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.TensorSliceProto.Extent)
  // optional int64 start = 1;
  if (this->start() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->start(), target);
  }

  // optional int64 length = 2;
  if (has_length()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->length(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.TensorSliceProto.Extent)
  return target;
}

size_t TensorSliceProto_Extent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.TensorSliceProto.Extent)
  size_t total_size = 0;

  // optional int64 start = 1;
  if (this->start() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->start());
  }

  switch (has_length_case()) {
    // optional int64 length = 2;
    case kLength: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->length());
      break;
    }
    case HAS_LENGTH_NOT_SET: {
      break;
    }
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TensorSliceProto_Extent::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.TensorSliceProto.Extent)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const TensorSliceProto_Extent* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const TensorSliceProto_Extent>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.TensorSliceProto.Extent)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.TensorSliceProto.Extent)
    UnsafeMergeFrom(*source);
  }
}

void TensorSliceProto_Extent::MergeFrom(const TensorSliceProto_Extent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.TensorSliceProto.Extent)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void TensorSliceProto_Extent::UnsafeMergeFrom(const TensorSliceProto_Extent& from) {
  GOOGLE_DCHECK(&from != this);
  switch (from.has_length_case()) {
    case kLength: {
      set_length(from.length());
      break;
    }
    case HAS_LENGTH_NOT_SET: {
      break;
    }
  }
  if (from.start() != 0) {
    set_start(from.start());
  }
}

void TensorSliceProto_Extent::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.TensorSliceProto.Extent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TensorSliceProto_Extent::CopyFrom(const TensorSliceProto_Extent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.TensorSliceProto.Extent)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool TensorSliceProto_Extent::IsInitialized() const {

  return true;
}

void TensorSliceProto_Extent::Swap(TensorSliceProto_Extent* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    TensorSliceProto_Extent temp;
    temp.UnsafeMergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void TensorSliceProto_Extent::UnsafeArenaSwap(TensorSliceProto_Extent* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void TensorSliceProto_Extent::InternalSwap(TensorSliceProto_Extent* other) {
  std::swap(start_, other->start_);
  std::swap(has_length_, other->has_length_);
  std::swap(_oneof_case_[0], other->_oneof_case_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata TensorSliceProto_Extent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TensorSliceProto_Extent_descriptor_;
  metadata.reflection = TensorSliceProto_Extent_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TensorSliceProto::kExtentFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TensorSliceProto::TensorSliceProto()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_tensor_5fslice_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.TensorSliceProto)
}
TensorSliceProto::TensorSliceProto(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena),
  extent_(arena) {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_InitDefaults_tensor_5fslice_2eproto();
#endif  // GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.TensorSliceProto)
}

void TensorSliceProto::InitAsDefaultInstance() {
}

TensorSliceProto::TensorSliceProto(const TensorSliceProto& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tensorflow.TensorSliceProto)
}

void TensorSliceProto::SharedCtor() {
  _cached_size_ = 0;
}

TensorSliceProto::~TensorSliceProto() {
  // @@protoc_insertion_point(destructor:tensorflow.TensorSliceProto)
  SharedDtor();
}

void TensorSliceProto::SharedDtor() {
  ::google::protobuf::Arena* arena = GetArenaNoVirtual();
  if (arena != NULL) {
    return;
  }

}

void TensorSliceProto::ArenaDtor(void* object) {
  TensorSliceProto* _this = reinterpret_cast< TensorSliceProto* >(object);
  (void)_this;
}
void TensorSliceProto::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void TensorSliceProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TensorSliceProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return TensorSliceProto_descriptor_;
}

const TensorSliceProto& TensorSliceProto::default_instance() {
  protobuf_InitDefaults_tensor_5fslice_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<TensorSliceProto> TensorSliceProto_default_instance_;

TensorSliceProto* TensorSliceProto::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<TensorSliceProto>(arena);
}

void TensorSliceProto::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.TensorSliceProto)
  extent_.Clear();
}

bool TensorSliceProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.TensorSliceProto)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .tensorflow.TensorSliceProto.Extent extent = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_extent:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_extent()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_extent;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.TensorSliceProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.TensorSliceProto)
  return false;
#undef DO_
}

void TensorSliceProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.TensorSliceProto)
  // repeated .tensorflow.TensorSliceProto.Extent extent = 1;
  for (unsigned int i = 0, n = this->extent_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->extent(i), output);
  }

  // @@protoc_insertion_point(serialize_end:tensorflow.TensorSliceProto)
}

::google::protobuf::uint8* TensorSliceProto::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.TensorSliceProto)
  // repeated .tensorflow.TensorSliceProto.Extent extent = 1;
  for (unsigned int i = 0, n = this->extent_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->extent(i), false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.TensorSliceProto)
  return target;
}

size_t TensorSliceProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.TensorSliceProto)
  size_t total_size = 0;

  // repeated .tensorflow.TensorSliceProto.Extent extent = 1;
  {
    unsigned int count = this->extent_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->extent(i));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TensorSliceProto::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.TensorSliceProto)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const TensorSliceProto* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const TensorSliceProto>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.TensorSliceProto)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.TensorSliceProto)
    UnsafeMergeFrom(*source);
  }
}

void TensorSliceProto::MergeFrom(const TensorSliceProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.TensorSliceProto)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void TensorSliceProto::UnsafeMergeFrom(const TensorSliceProto& from) {
  GOOGLE_DCHECK(&from != this);
  extent_.MergeFrom(from.extent_);
}

void TensorSliceProto::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.TensorSliceProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TensorSliceProto::CopyFrom(const TensorSliceProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.TensorSliceProto)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool TensorSliceProto::IsInitialized() const {

  return true;
}

void TensorSliceProto::Swap(TensorSliceProto* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    TensorSliceProto temp;
    temp.UnsafeMergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void TensorSliceProto::UnsafeArenaSwap(TensorSliceProto* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void TensorSliceProto::InternalSwap(TensorSliceProto* other) {
  extent_.UnsafeArenaSwap(&other->extent_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata TensorSliceProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = TensorSliceProto_descriptor_;
  metadata.reflection = TensorSliceProto_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// TensorSliceProto_Extent

// optional int64 start = 1;
void TensorSliceProto_Extent::clear_start() {
  start_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 TensorSliceProto_Extent::start() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorSliceProto.Extent.start)
  return start_;
}
void TensorSliceProto_Extent::set_start(::google::protobuf::int64 value) {
  
  start_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.TensorSliceProto.Extent.start)
}

// optional int64 length = 2;
bool TensorSliceProto_Extent::has_length() const {
  return has_length_case() == kLength;
}
void TensorSliceProto_Extent::set_has_length() {
  _oneof_case_[0] = kLength;
}
void TensorSliceProto_Extent::clear_length() {
  if (has_length()) {
    has_length_.length_ = GOOGLE_LONGLONG(0);
    clear_has_has_length();
  }
}
::google::protobuf::int64 TensorSliceProto_Extent::length() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorSliceProto.Extent.length)
  if (has_length()) {
    return has_length_.length_;
  }
  return GOOGLE_LONGLONG(0);
}
void TensorSliceProto_Extent::set_length(::google::protobuf::int64 value) {
  if (!has_length()) {
    clear_has_length();
    set_has_length();
  }
  has_length_.length_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.TensorSliceProto.Extent.length)
}

bool TensorSliceProto_Extent::has_has_length() const {
  return has_length_case() != HAS_LENGTH_NOT_SET;
}
void TensorSliceProto_Extent::clear_has_has_length() {
  _oneof_case_[0] = HAS_LENGTH_NOT_SET;
}
TensorSliceProto_Extent::HasLengthCase TensorSliceProto_Extent::has_length_case() const {
  return TensorSliceProto_Extent::HasLengthCase(_oneof_case_[0]);
}
inline const TensorSliceProto_Extent* TensorSliceProto_Extent::internal_default_instance() {
  return &TensorSliceProto_Extent_default_instance_.get();
}
// -------------------------------------------------------------------

// TensorSliceProto

// repeated .tensorflow.TensorSliceProto.Extent extent = 1;
int TensorSliceProto::extent_size() const {
  return extent_.size();
}
void TensorSliceProto::clear_extent() {
  extent_.Clear();
}
const ::tensorflow::TensorSliceProto_Extent& TensorSliceProto::extent(int index) const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorSliceProto.extent)
  return extent_.Get(index);
}
::tensorflow::TensorSliceProto_Extent* TensorSliceProto::mutable_extent(int index) {
  // @@protoc_insertion_point(field_mutable:tensorflow.TensorSliceProto.extent)
  return extent_.Mutable(index);
}
::tensorflow::TensorSliceProto_Extent* TensorSliceProto::add_extent() {
  // @@protoc_insertion_point(field_add:tensorflow.TensorSliceProto.extent)
  return extent_.Add();
}
::google::protobuf::RepeatedPtrField< ::tensorflow::TensorSliceProto_Extent >*
TensorSliceProto::mutable_extent() {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.TensorSliceProto.extent)
  return &extent_;
}
const ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorSliceProto_Extent >&
TensorSliceProto::extent() const {
  // @@protoc_insertion_point(field_list:tensorflow.TensorSliceProto.extent)
  return extent_;
}

inline const TensorSliceProto* TensorSliceProto::internal_default_instance() {
  return &TensorSliceProto_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)
