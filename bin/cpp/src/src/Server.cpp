// Generated by Haxe 4.3.1
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_handle_OfflinePingPong
#include <handle/OfflinePingPong.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_src_Server
#include <src/Server.h>
#endif
#ifndef INCLUDED_sys_net_Address
#include <sys/net/Address.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
#ifndef INCLUDED_sys_net_UdpSocket
#include <sys/net/UdpSocket.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_2f4ae0c182bac71e_19_new,"src.Server","new",0x71c70e9f,"src.Server.new","Server.hx",19,0x1acdb3bb)
HX_LOCAL_STACK_FRAME(_hx_pos_2f4ae0c182bac71e_29_Start,"src.Server","Start",0x3aa77041,"src.Server.Start","Server.hx",29,0x1acdb3bb)
HX_LOCAL_STACK_FRAME(_hx_pos_2f4ae0c182bac71e_36_HandlePackets,"src.Server","HandlePackets",0x16029c02,"src.Server.HandlePackets","Server.hx",36,0x1acdb3bb)
namespace src{

void Server_obj::__construct(::String hostName,::String ip,int port){
            	HX_GC_STACKFRAME(&_hx_pos_2f4ae0c182bac71e_19_new)
HXLINE(  20)		::haxe::Log_obj::trace(HX_("\x1b""[31mSocket installing..\x1b""[0m",e2,0a,e3,7b),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),20,HX_("src.Server",2d,d3,1d,8b),HX_("new",60,d0,53,00)));
HXLINE(  21)		this->HostName = hostName;
HXLINE(  22)		this->Ip = ip;
HXLINE(  23)		this->Port = port;
HXLINE(  24)		this->IpHost =  ::sys::net::Host_obj::__alloc( HX_CTX ,this->Ip.toString());
HXLINE(  25)		this->UdpServer =  ::sys::net::UdpSocket_obj::__alloc( HX_CTX );
            	}

Dynamic Server_obj::__CreateEmpty() { return new Server_obj; }

void *Server_obj::_hx_vtable = 0;

Dynamic Server_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Server_obj > _hx_result = new Server_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool Server_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0a07c753;
}

void Server_obj::Start(){
            	HX_STACKFRAME(&_hx_pos_2f4ae0c182bac71e_29_Start)
HXLINE(  30)		::haxe::Log_obj::trace(HX_("Socket installed",ad,0b,a0,46),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),30,HX_("src.Server",2d,d3,1d,8b),HX_("Start",42,e4,38,17)));
HXLINE(  31)		this->UdpServer->bind(this->IpHost,this->Port);
HXLINE(  32)		this->HandlePackets();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Server_obj,Start,(void))

void Server_obj::HandlePackets(){
            	HX_GC_STACKFRAME(&_hx_pos_2f4ae0c182bac71e_36_HandlePackets)
HXLINE(  37)		int buffersize = 1024;
HXLINE(  38)		while(true){
HXLINE(  39)			this->AllAdd =  ::sys::net::Address_obj::__alloc( HX_CTX );
HXLINE(  40)			 ::haxe::io::Bytes buffer = ::haxe::io::Bytes_obj::alloc(buffersize);
HXLINE(  42)			try {
            				HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE(  43)				int numBytes = this->UdpServer->readFrom(buffer,0,buffersize,this->AllAdd);
            			} catch( ::Dynamic _hx_e) {
            				if (_hx_e.IsClass<  ::Dynamic >() ){
            					HX_STACK_BEGIN_CATCH
            					 ::Dynamic _g = _hx_e;
HXLINE(  45)					{
HXLINE(  45)						null();
            					}
HXDLIN(  45)					 ::Dynamic e = _g;
HXLINE(  46)					{
HXLINE(  46)						 ::Dynamic _hx_tmp = ::haxe::Log_obj::trace;
HXDLIN(  46)						::String _hx_tmp1;
HXDLIN(  46)						if (::hx::IsNull( e )) {
HXLINE(  46)							_hx_tmp1 = HX_("null",87,9e,0e,49);
            						}
            						else {
HXLINE(  46)							_hx_tmp1 = ::Std_obj::string(e);
            						}
HXDLIN(  46)						_hx_tmp(_hx_tmp1,::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),46,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
            					}
            				}
            				else {
            					HX_STACK_DO_THROW(_hx_e);
            				}
            			}
HXLINE(  49)			 ::haxe::io::BytesInput bytesinput =  ::haxe::io::BytesInput_obj::__alloc( HX_CTX ,buffer,null(),null());
HXLINE(  50)			 ::haxe::io::Bytes bytes = bytesinput->read(buffersize);
HXLINE(  51)			 ::haxe::io::Bytes packet = bytes->sub(0,1);
HXLINE(  52)			::String packetsend = packet->toHex();
HXLINE(  53)			if ((packetsend == HX_("01",01,2a,00,00))) {
HXLINE(  54)				this->offlineping =  ::handle::OfflinePingPong_obj::__alloc( HX_CTX ,bytes,this->AllAdd,this->UdpServer);
HXLINE(  55)				this->offlineping->Offline_Ping();
            			}
            			else {
HXLINE(  57)				if ((packetsend == HX_("05",05,2a,00,00))) {
HXLINE(  58)					::haxe::Log_obj::trace(HX_("Open Connection Request 1",94,62,26,19),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),58,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
HXLINE(  59)					 ::haxe::io::Bytes packet1 = bytes->sub(0,1);
HXLINE(  60)					 ::Dynamic _hx_tmp2 = ::haxe::Log_obj::trace;
HXDLIN(  60)					::String _hx_tmp3 = ((HX_("Packet Id: ",d9,2a,e7,03) + HX_("0x",48,2a,00,00)) + packet1->toHex());
HXDLIN(  60)					_hx_tmp2(_hx_tmp3,::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),60,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
HXLINE(  62)					 ::haxe::io::Bytes magicsubs = bytes->sub(2,16);
HXLINE(  63)					::String RakNetMagic = magicsubs->toHex();
HXLINE(  65)					::haxe::Log_obj::trace((HX_("RakNet Magic:",cc,1c,5f,f3) + RakNetMagic),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),65,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
HXLINE(  67)					 ::haxe::io::Bytes protocol = bytes->sub(19,1);
HXLINE(  68)					::String protocolstr = bytes->toHex();
HXLINE(  70)					::haxe::Log_obj::trace((HX_("Protocol Version:",ea,08,38,29) + protocolstr),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),70,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
HXLINE(  72)					 ::haxe::io::Bytes mtu = bytes->sub(20,46);
HXLINE(  73)					::haxe::Log_obj::trace((HX_("mtu size:",e7,45,39,05) + mtu->length),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),73,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
            				}
            				else {
HXLINE(  76)					::haxe::Log_obj::trace(HX_("other packets",9b,3a,74,98),::hx::SourceInfo(HX_("src/Server.hx",90,61,34,db),76,HX_("src.Server",2d,d3,1d,8b),HX_("HandlePackets",03,79,19,a2)));
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(Server_obj,HandlePackets,(void))


::hx::ObjectPtr< Server_obj > Server_obj::__new(::String hostName,::String ip,int port) {
	::hx::ObjectPtr< Server_obj > __this = new Server_obj();
	__this->__construct(hostName,ip,port);
	return __this;
}

::hx::ObjectPtr< Server_obj > Server_obj::__alloc(::hx::Ctx *_hx_ctx,::String hostName,::String ip,int port) {
	Server_obj *__this = (Server_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Server_obj), true, "src.Server"));
	*(void **)__this = Server_obj::_hx_vtable;
	__this->__construct(hostName,ip,port);
	return __this;
}

Server_obj::Server_obj()
{
}

void Server_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Server);
	HX_MARK_MEMBER_NAME(HostName,"HostName");
	HX_MARK_MEMBER_NAME(Ip,"Ip");
	HX_MARK_MEMBER_NAME(Port,"Port");
	HX_MARK_MEMBER_NAME(UdpServer,"UdpServer");
	HX_MARK_MEMBER_NAME(IpHost,"IpHost");
	HX_MARK_MEMBER_NAME(AllAdd,"AllAdd");
	HX_MARK_MEMBER_NAME(offlineping,"offlineping");
	HX_MARK_END_CLASS();
}

void Server_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(HostName,"HostName");
	HX_VISIT_MEMBER_NAME(Ip,"Ip");
	HX_VISIT_MEMBER_NAME(Port,"Port");
	HX_VISIT_MEMBER_NAME(UdpServer,"UdpServer");
	HX_VISIT_MEMBER_NAME(IpHost,"IpHost");
	HX_VISIT_MEMBER_NAME(AllAdd,"AllAdd");
	HX_VISIT_MEMBER_NAME(offlineping,"offlineping");
}

::hx::Val Server_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"Ip") ) { return ::hx::Val( Ip ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Port") ) { return ::hx::Val( Port ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Start") ) { return ::hx::Val( Start_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"IpHost") ) { return ::hx::Val( IpHost ); }
		if (HX_FIELD_EQ(inName,"AllAdd") ) { return ::hx::Val( AllAdd ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HostName") ) { return ::hx::Val( HostName ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"UdpServer") ) { return ::hx::Val( UdpServer ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"offlineping") ) { return ::hx::Val( offlineping ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"HandlePackets") ) { return ::hx::Val( HandlePackets_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Server_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"Ip") ) { Ip=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Port") ) { Port=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"IpHost") ) { IpHost=inValue.Cast<  ::sys::net::Host >(); return inValue; }
		if (HX_FIELD_EQ(inName,"AllAdd") ) { AllAdd=inValue.Cast<  ::sys::net::Address >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HostName") ) { HostName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"UdpServer") ) { UdpServer=inValue.Cast<  ::sys::net::UdpSocket >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"offlineping") ) { offlineping=inValue.Cast<  ::handle::OfflinePingPong >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Server_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("HostName",f3,fd,5c,17));
	outFields->push(HX_("Ip",07,40,00,00));
	outFields->push(HX_("Port",a1,af,35,35));
	outFields->push(HX_("UdpServer",c4,24,0c,36));
	outFields->push(HX_("IpHost",0f,4b,da,dc));
	outFields->push(HX_("AllAdd",a0,cf,0d,74));
	outFields->push(HX_("offlineping",d5,2e,f4,26));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Server_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(Server_obj,HostName),HX_("HostName",f3,fd,5c,17)},
	{::hx::fsString,(int)offsetof(Server_obj,Ip),HX_("Ip",07,40,00,00)},
	{::hx::fsInt,(int)offsetof(Server_obj,Port),HX_("Port",a1,af,35,35)},
	{::hx::fsObject /*  ::sys::net::UdpSocket */ ,(int)offsetof(Server_obj,UdpServer),HX_("UdpServer",c4,24,0c,36)},
	{::hx::fsObject /*  ::sys::net::Host */ ,(int)offsetof(Server_obj,IpHost),HX_("IpHost",0f,4b,da,dc)},
	{::hx::fsObject /*  ::sys::net::Address */ ,(int)offsetof(Server_obj,AllAdd),HX_("AllAdd",a0,cf,0d,74)},
	{::hx::fsObject /*  ::handle::OfflinePingPong */ ,(int)offsetof(Server_obj,offlineping),HX_("offlineping",d5,2e,f4,26)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Server_obj_sStaticStorageInfo = 0;
#endif

static ::String Server_obj_sMemberFields[] = {
	HX_("HostName",f3,fd,5c,17),
	HX_("Ip",07,40,00,00),
	HX_("Port",a1,af,35,35),
	HX_("UdpServer",c4,24,0c,36),
	HX_("IpHost",0f,4b,da,dc),
	HX_("AllAdd",a0,cf,0d,74),
	HX_("offlineping",d5,2e,f4,26),
	HX_("Start",42,e4,38,17),
	HX_("HandlePackets",03,79,19,a2),
	::String(null()) };

::hx::Class Server_obj::__mClass;

void Server_obj::__register()
{
	Server_obj _hx_dummy;
	Server_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("src.Server",2d,d3,1d,8b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Server_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Server_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Server_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Server_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace src
