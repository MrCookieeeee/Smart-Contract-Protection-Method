#include "mpk_apis.h"
#include <cstring> 
#include <node.h>
#define DOMAIN 20
int vpkeys[DOMAIN];
const char* private_key = "0fe16c53b1db662fde8dfd335bd5905c9c6dbb74e0117f34d0a1ef3aad6f2a4e";
namespace demo {
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::String;
  using v8::Object;
  using v8::Value;

  void GetString(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    
    printf("Call Intel Mpk.....\n");
    mpt_init(0.5);
    char *addr[10];
    addr[0] = (char *)malloc(strlen(private_key) + 1);
    vpkeys[0] = rwmmap((void**)&addr[0]);
    BRIDGE_DOMAINRW(vpkeys[0]);
    
    strcpy(addr[0], private_key); 
    printf("giving the access of domain :%s\n", addr[0]);

    // Create a V8 string from the char* array
    Local<String> v8String = String::NewFromUtf8(isolate, addr[0]).ToLocalChecked();

    printf("Exit the read write permission fo the domain\n");
    EXIT_DOMAIN(vpkeys[0]);
    DESTROY_DOMAIN(vpkeys[0]);
    //printf("%s\n", addr[0]);

   


    // Return the V8 string
    args.GetReturnValue().Set(v8String);
  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "getString", GetString);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}
