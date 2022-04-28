#pragma once
// ----- THIS IS NOT WEBCORE ----
// It reuses the namespace.
// ----- THIS IS NOT WEBCORE ----

// Node.js buffer

#include "root.h"

#include "BufferEncodingType.h"
#include "JavaScriptCore/GenericTypedArrayView.h"

extern "C" JSC::EncodedJSValue Bun__encoding__toStringUTF16(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);
extern "C" JSC::EncodedJSValue Bun__encoding__toStringUTF8(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);
extern "C" JSC::EncodedJSValue Bun__encoding__toStringASCII(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);
extern "C" JSC::EncodedJSValue Bun__encoding__toStringLatin1(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);
extern "C" JSC::EncodedJSValue Bun__encoding__toStringHex(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);
extern "C" JSC::EncodedJSValue Bun__encoding__toStringBase64(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);
extern "C" JSC::EncodedJSValue Bun__encoding__toStringURLSafeBase64(const uint8_t* input, size_t len, JSC::JSGlobalObject* globalObject);

namespace WebCore {

class Buffer final : public RefCounted<Buffer> {
public:
    using Adaptor = JSC::JSUint8Array::Adaptor;
    ~Buffer();

    static int32_t write(WTF::StringView view, size_t offset, size_t length, BufferEncodingType encodingType);

    static Ref<Buffer> create(JSC::JSGlobalObject* globalObject, JSC::JSUint8Array*, size_t byteOffset, size_t length);
    static Ref<Buffer> create(JSC::JSGlobalObject* globalObject, JSC::JSUint8Array*);

    static Ref<Buffer> createEmpty(JSC::JSGlobalObject* globalObject);
    static Ref<Buffer> create(JSC::JSGlobalObject* globalObject, UChar* ptr, size_t len, BufferEncodingType encoding);
    static Ref<Buffer> create(JSC::JSGlobalObject* globalObject, LChar* ptr, size_t len, BufferEncodingType encoding);

    static Ref<Buffer> create(JSC::JSGlobalObject* globalObject, WTF::StringView&, BufferEncodingType encoding);
    static Ref<Buffer> create(JSC::JSGlobalObject* globalObject, WTF::String&, BufferEncodingType encoding);

    Buffer(JSC::JSGlobalObject* globalObject, JSC::JSUint8Array* array, size_t byteOffset,
        size_t length)
        : m_array(array)

    {
    }

    JSC::JSUint8Array* m_array;
};

}