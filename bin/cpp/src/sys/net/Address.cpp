// Generated by Haxe 4.3.1
#include <hxcpp.h>

#ifndef INCLUDED_sys_net_Address
#include <sys/net/Address.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_50abb57b9095acaa_33_new,"sys.net.Address","new",0x3f906994,"sys.net.Address.new","E:\\New folder (9)\\haxe\\std/sys/net/Address.hx",33,0xcd01df31)
namespace sys{
namespace net{

void Address_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_50abb57b9095acaa_33_new)
HXLINE(  34)		this->host = 0;
HXLINE(  35)		this->port = 0;
            	}

Dynamic Address_obj::__CreateEmpty() { return new Address_obj; }

void *Address_obj::_hx_vtable = 0;

Dynamic Address_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Address_obj > _hx_result = new Address_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Address_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7f9d1330;
}


Address_obj::Address_obj()
{
}

::hx::Val Address_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { return ::hx::Val( host ); }
		if (HX_FIELD_EQ(inName,"port") ) { return ::hx::Val( port ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Address_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { host=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"port") ) { port=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Address_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("host",68,cf,12,45));
	outFields->push(HX_("port",81,83,5c,4a));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Address_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Address_obj,host),HX_("host",68,cf,12,45)},
	{::hx::fsInt,(int)offsetof(Address_obj,port),HX_("port",81,83,5c,4a)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Address_obj_sStaticStorageInfo = 0;
#endif

static ::String Address_obj_sMemberFields[] = {
	HX_("host",68,cf,12,45),
	HX_("port",81,83,5c,4a),
	::String(null()) };

::hx::Class Address_obj::__mClass;

void Address_obj::__register()
{
	Address_obj _hx_dummy;
	Address_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("sys.net.Address",a2,4f,97,9a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Address_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Address_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Address_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Address_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace sys
} // end namespace net
