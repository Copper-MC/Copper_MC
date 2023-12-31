// Generated by Haxe 4.3.1
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_3dcd6fb3186e268e_34_new,"haxe.io.Bytes","new",0x3938d57d,"haxe.io.Bytes.new","E:\\New folder (9)\\haxe\\std/haxe/io/Bytes.hx",34,0xce224446)
HX_LOCAL_STACK_FRAME(_hx_pos_3dcd6fb3186e268e_155_sub,"haxe.io.Bytes","sub",0x393cae9d,"haxe.io.Bytes.sub","E:\\New folder (9)\\haxe\\std/haxe/io/Bytes.hx",155,0xce224446)
HX_LOCAL_STACK_FRAME(_hx_pos_3dcd6fb3186e268e_524_toHex,"haxe.io.Bytes","toHex",0x14173a7d,"haxe.io.Bytes.toHex","E:\\New folder (9)\\haxe\\std/haxe/io/Bytes.hx",524,0xce224446)
HX_LOCAL_STACK_FRAME(_hx_pos_3dcd6fb3186e268e_549_alloc,"haxe.io.Bytes","alloc",0x2199ead2,"haxe.io.Bytes.alloc","E:\\New folder (9)\\haxe\\std/haxe/io/Bytes.hx",549,0xce224446)
HX_LOCAL_STACK_FRAME(_hx_pos_3dcd6fb3186e268e_580_ofString,"haxe.io.Bytes","ofString",0x6e53bb0b,"haxe.io.Bytes.ofString","E:\\New folder (9)\\haxe\\std/haxe/io/Bytes.hx",580,0xce224446)
namespace haxe{
namespace io{

void Bytes_obj::__construct(int length,::Array< unsigned char > b){
            	HX_STACKFRAME(&_hx_pos_3dcd6fb3186e268e_34_new)
HXLINE(  35)		this->length = length;
HXLINE(  36)		this->b = b;
            	}

Dynamic Bytes_obj::__CreateEmpty() { return new Bytes_obj; }

void *Bytes_obj::_hx_vtable = 0;

Dynamic Bytes_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Bytes_obj > _hx_result = new Bytes_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Bytes_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x195c64b7;
}

 ::haxe::io::Bytes Bytes_obj::sub(int pos,int len){
            	HX_GC_STACKFRAME(&_hx_pos_3dcd6fb3186e268e_155_sub)
HXLINE( 157)		bool _hx_tmp;
HXDLIN( 157)		bool _hx_tmp1;
HXDLIN( 157)		if ((pos >= 0)) {
HXLINE( 157)			_hx_tmp1 = (len < 0);
            		}
            		else {
HXLINE( 157)			_hx_tmp1 = true;
            		}
HXDLIN( 157)		if (!(_hx_tmp1)) {
HXLINE( 157)			_hx_tmp = ((pos + len) > this->length);
            		}
            		else {
HXLINE( 157)			_hx_tmp = true;
            		}
HXDLIN( 157)		if (_hx_tmp) {
HXLINE( 158)			HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds_dyn());
            		}
HXLINE( 178)		return  ::haxe::io::Bytes_obj::__alloc( HX_CTX ,len,this->b->slice(pos,(pos + len)));
            	}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,sub,return )

::String Bytes_obj::toHex(){
            	HX_GC_STACKFRAME(&_hx_pos_3dcd6fb3186e268e_524_toHex)
HXLINE( 525)		 ::StringBuf s =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 526)		::Array< ::Dynamic> chars = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 527)		::String str = HX_("0123456789abcdef",68,7e,d5,ef);
HXLINE( 528)		{
HXLINE( 528)			int _g = 0;
HXDLIN( 528)			int _g1 = str.length;
HXDLIN( 528)			while((_g < _g1)){
HXLINE( 528)				_g = (_g + 1);
HXDLIN( 528)				int i = (_g - 1);
HXLINE( 529)				chars->push(str.charCodeAt(i));
            			}
            		}
HXLINE( 530)		{
HXLINE( 530)			int _g2 = 0;
HXDLIN( 530)			int _g3 = this->length;
HXDLIN( 530)			while((_g2 < _g3)){
HXLINE( 530)				_g2 = (_g2 + 1);
HXDLIN( 530)				int i1 = (_g2 - 1);
HXLINE( 531)				int c = ( (int)(this->b->__get(i1)) );
HXLINE( 532)				{
HXLINE( 532)					int c1 = ( (int)(chars->__get((c >> 4))) );
HXDLIN( 532)					if ((c1 >= 127)) {
HXLINE( 532)						::String x = ::String::fromCharCode(c1);
HXDLIN( 532)						if (::hx::IsNotNull( s->charBuf )) {
HXLINE( 532)							s->flush();
            						}
HXDLIN( 532)						if (::hx::IsNull( s->b )) {
HXLINE( 532)							s->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x));
            						}
            						else {
HXLINE( 532)							::Array< ::String > s1 = s->b;
HXDLIN( 532)							s1->push(::Std_obj::string(x));
            						}
            					}
            					else {
HXLINE( 532)						if (::hx::IsNull( s->charBuf )) {
HXLINE( 532)							s->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 532)						s->charBuf->push(c1);
            					}
            				}
HXLINE( 533)				{
HXLINE( 533)					int c2 = ( (int)(chars->__get((c & 15))) );
HXDLIN( 533)					if ((c2 >= 127)) {
HXLINE( 533)						::String x1 = ::String::fromCharCode(c2);
HXDLIN( 533)						if (::hx::IsNotNull( s->charBuf )) {
HXLINE( 533)							s->flush();
            						}
HXDLIN( 533)						if (::hx::IsNull( s->b )) {
HXLINE( 533)							s->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(x1));
            						}
            						else {
HXLINE( 533)							::Array< ::String > s2 = s->b;
HXDLIN( 533)							s2->push(::Std_obj::string(x1));
            						}
            					}
            					else {
HXLINE( 533)						if (::hx::IsNull( s->charBuf )) {
HXLINE( 533)							s->charBuf = ::Array_obj< char >::__new();
            						}
HXDLIN( 533)						s->charBuf->push(c2);
            					}
            				}
            			}
            		}
HXLINE( 535)		return s->toString();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toHex,return )

 ::haxe::io::Bytes Bytes_obj::alloc(int length){
            	HX_GC_STACKFRAME(&_hx_pos_3dcd6fb3186e268e_549_alloc)
HXLINE( 557)		::Array< unsigned char > a = ::Array_obj< unsigned char >::__new();
HXLINE( 558)		if ((length > 0)) {
HXLINE( 559)			_hx_array_set_size_exact(a,length);
            		}
HXLINE( 560)		return  ::haxe::io::Bytes_obj::__alloc( HX_CTX ,length,a);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,alloc,return )

 ::haxe::io::Bytes Bytes_obj::ofString(::String s, ::haxe::io::Encoding encoding){
            	HX_GC_STACKFRAME(&_hx_pos_3dcd6fb3186e268e_580_ofString)
HXLINE( 591)		::Array< unsigned char > a = ::Array_obj< unsigned char >::__new();
HXLINE( 592)		 ::__hxcpp_bytes_of_string(a,s);
HXLINE( 593)		return  ::haxe::io::Bytes_obj::__alloc( HX_CTX ,a->length,a);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,ofString,return )


::hx::ObjectPtr< Bytes_obj > Bytes_obj::__new(int length,::Array< unsigned char > b) {
	::hx::ObjectPtr< Bytes_obj > __this = new Bytes_obj();
	__this->__construct(length,b);
	return __this;
}

::hx::ObjectPtr< Bytes_obj > Bytes_obj::__alloc(::hx::Ctx *_hx_ctx,int length,::Array< unsigned char > b) {
	Bytes_obj *__this = (Bytes_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Bytes_obj), true, "haxe.io.Bytes"));
	*(void **)__this = Bytes_obj::_hx_vtable;
	__this->__construct(length,b);
	return __this;
}

Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bytes);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void Bytes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(b,"b");
}

::hx::Val Bytes_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return ::hx::Val( b ); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sub") ) { return ::hx::Val( sub_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"toHex") ) { return ::hx::Val( toHex_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return ::hx::Val( length ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Bytes_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"alloc") ) { outValue = alloc_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ofString") ) { outValue = ofString_dyn(); return true; }
	}
	return false;
}

::hx::Val Bytes_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< ::Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("length",e6,94,07,9f));
	outFields->push(HX_("b",62,00,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Bytes_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Bytes_obj,length),HX_("length",e6,94,07,9f)},
	{::hx::fsObject /* ::Array< unsigned char > */ ,(int)offsetof(Bytes_obj,b),HX_("b",62,00,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Bytes_obj_sStaticStorageInfo = 0;
#endif

static ::String Bytes_obj_sMemberFields[] = {
	HX_("length",e6,94,07,9f),
	HX_("b",62,00,00,00),
	HX_("sub",80,a9,57,00),
	HX_("toHex",20,f4,10,14),
	::String(null()) };

::hx::Class Bytes_obj::__mClass;

static ::String Bytes_obj_sStaticFields[] = {
	HX_("alloc",75,a4,93,21),
	HX_("ofString",48,69,31,a4),
	::String(null())
};

void Bytes_obj::__register()
{
	Bytes_obj _hx_dummy;
	Bytes_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("haxe.io.Bytes",0b,53,6f,9f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Bytes_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Bytes_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Bytes_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Bytes_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Bytes_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Bytes_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace haxe
} // end namespace io
