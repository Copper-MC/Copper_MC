// Generated by Haxe 4.3.1
#ifndef INCLUDED_sys_net_Address
#define INCLUDED_sys_net_Address

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_50abb57b9095acaa_33_new)
HX_DECLARE_CLASS2(sys,net,Address)

namespace sys{
namespace net{


class HXCPP_CLASS_ATTRIBUTES Address_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Address_obj OBJ_;
		Address_obj();

	public:
		enum { _hx_ClassId = 0x7f9d1330 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="sys.net.Address")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"sys.net.Address"); }

		inline static ::hx::ObjectPtr< Address_obj > __new() {
			::hx::ObjectPtr< Address_obj > __this = new Address_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Address_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Address_obj *__this = (Address_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Address_obj), false, "sys.net.Address"));
			*(void **)__this = Address_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_50abb57b9095acaa_33_new)
HXLINE(  34)		( ( ::sys::net::Address)(__this) )->host = 0;
HXLINE(  35)		( ( ::sys::net::Address)(__this) )->port = 0;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Address_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Address",94,99,5c,6a); }

		int host;
		int port;
};

} // end namespace sys
} // end namespace net

#endif /* INCLUDED_sys_net_Address */ 
