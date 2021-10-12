#ifndef defs-ISAPI_H_
#define defs-ISAPI_H_
using namespace std;

#define DEVICE_INFO_CONFIG_CMD "/ISAPI/System/deviceInfo"
#define DEVICE_INFO_CONFIG_XML "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<DeviceInfo>"\
"<model>AC-PT12-WA</model>"\
"<serialNumber>E95A20121800059</serialNumber>"\
"</DeviceInfo>"\



#define LED_CONTROL_CONFIG_CMD "/ISAPI/System/IO/LEDControl"
#define LED_CONTROL_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<LEDControl version=\"2.0\" xmlns=\"http://www.isapi.org/ver20/XMLSchema\">"\
"<control>true</control>"\
"<blue>false</blue>"\
"<red>true</red>"\
"</LEDControl>"\


#define IR_LIGHT_SWITCH_CONFIG_CMD "/ISAPI/System/Hardware/IrLightSwitch"



#define AUDIO_CAP_CONFIG_CMD "/ISAPI/System/Audio/capabilities"
#define AUDIO_CAP_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<AudioCap>"\
"<audioInputNums>1</audioInputNums>"\
"</AudioCap>"\


#define IMAGE_FLIP_CONFIG_CMD "/ISAPI/Image/channels/id/imageFlip"




#define NETWORK_INTERFACE_CONFIG_CMD "/ISAPI/System/Network/interfaces/id"
#define NETWORK_INTERFACE_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<NetworkInterface>"\
"<IPAddress>"\
"<addressingType>dynamic</addressingType>"\
"<ipAddress>192.168.1.11</ipAddress>"\
"<subnetMask>255.255.255.0</subnetMask>"\
"<DefaultGateway>"\
"<ipAddress>192.168.1.1</ipAddress>"\
"</DefaultGateway>"\
"<PrimaryDNS>"\
"<ipAddress>192.168.1.1</ipAddress>"\
"</PrimaryDNS>"\
"<SecondaryDNS>"\
"<ipAddress></ipAddress>"\
"</SecondaryDNS>"\
"</IPAddress>"\
"<Link>"\
"<MACAddress>a0:9f:10:1f:46:b9</MACAddress>"\
"</Link>"\
"</NetworkInterface>"\


#define VEDIO_INPUT_CHANNELS_CONFIG_CMD "/ISAPI/System/Video/inputs/channels/id"


#define STREAMING_CHANNELS_PICTURE_CONFIG_CMD "/ISAPI/Streaming/channels/id/picture"

#define DYNAMIC_CAP_CONFIG_CMD "/ISAPI/Streaming/channels/id/dynamicCap"
#define DYNAMIC_CAP_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<StreamingChannel>"\
"<Video>"\
"<videoQualityControlType>cbr,vbr,avbr</videoQualityControlType>"\
"<BitRate>"\
"<min>64</min>"\
"<max>2000</max>"\
"</BitRate>"\
"<FrameRate>"\
"<min>5</min>"\
"<max>15</max>"\
"</FrameRate>"\
"<GovLength>"\
"<min>1</min>"\
"<max>50</max>"\
"</GovLength>"\
"<Resolution>"\
"<ResolutionAvailable>"\
"<width>1920</width>"\
"<Height>1080</Height>"\
"</ResolutionAvailable>"\
"<ResolutionAvailable>"\
"<width>1280</width>"\
"<Height>720</Height>"\
"</ResolutionAvailable>"\
"<ResolutionAvailable>"\
"<width>720</width>"\
"<Height>480</Height>"\
"</ResolutionAvailable>"\
"</Resolution>"\
"</Video>"\
"</StreamingChannel>"\


#define STREAMING_CHANNELS_CONFIG_CMD "/ISAPI/Streaming/channels/id"
#define STREAMING_CHANNELS_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<StreamingChannel>"\
"<Video>"\
"<enabled>true</enabled>"\
"<videoCodecType>H.264</videoCodecType>"\
"<videoResolutionWidth>1280</videoResolutionWidth>"\
"<videoResolutionHeight>720</videoResolutionHeight>"\
"<videoQualityControlType>avbr</videoQualityControlType>"\
"<vbrUpperCap>256</vbrUpperCap>"\
"<maxFrameRate>8</maxFrameRate>"\
"<GovLength>30</GovLength>"\
"<fixedQuality>100</fixedQuality>"\
"<H264Profile>Main</H264Profile>"\
"</Video>"\
"<Audio>"\
"<enabled>true</enabled>"\
"<audioCompressionType>G.711alaw</audioCompressionType>"\
"<audioInputChannelID>1</audioInputChannelID>"\
"</Audio>"\
"</StreamingChannel>"\


#define VIDEO_INPUT_CHANNEL_NAMEOVERLAY   "/ISAPI/System/Video/inputs/channels/id/overlays/channelNameOverlay"

#define VIDEO_INPUT_CHANNEL_OVERLAY_CMD "/ISAPI/System/Video/inputs/channels/id/overlays/dateTimeOverlay"

#define PTZCTRL_PRIVACY_MODE_CONFIG_CMD "/ISAPI/PTZCtrl/channels/1/privacyMode"


#define PTZCTRL_CONTINUOUS_EX_CONFIG_CMD "/ISAPI/PTZCtrl/channels/1/continuousEx"

#define PTRCTRL_PRESETS_EX_CONFIG_CMD "/ISAPI/PTZCtrl/channels/1/presetsEx/"
#define PTRCTRL_PRESETS_EX_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<PTZPresetList>"\
"<PTZPreset>"\
"<index>1</index>"\
"</PTZPreset>"\
"</PTZPresetList>"\


#define PTZCTRL_CALL_CONFIG_CMD "/ISAPI/PTZCtrl/channels/1/presetsEx/id/call"


#define SYSTHEM_TIME_CONFIG_CMD "/ISAPI/System/time"


#define NETWORK_INTERFACES_IDNETINTERFACE_WIRELESS_CONFIG_CMD "/ISAPI/System/Network/interfaces/IdNetInterface/wireless"


#define IPC_OEM_TRANSDATA_CONFIG_CMD "/ISAPI/IPC/OEM/transData"

#define MOTION_DETECTION_CONFIG_CMD" /ISAPI/System/Video/inputs/channels/id/motionDetection"
#define MOTION_DETECTION_CONFIG_XML"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<MotionDetection>"\
"<enabled>true</enabled>"\
"<samplingInterval>2</samplingInterval>"\
"<Grid>"\
"<rowGranularity>18</rowGranularity>"\
"<columnGranularity>22</columnGranularity>"\
"</Grid>"\
"<MotionDetectionLayout>"\
"<sensitivityLevel>70</sensitivityLevel>"\
"<layout>"\
"<gridMap>FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF</gridMap>"\
"</layout>"\
"</MotionDetectionLayout>"\
"</MotionDetection>"\

#define USER_LIST_CONFIG_CMD "/ISAPI/Security/users"
#define USER_LIST_CONFIG_XML  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"\
"<UserList>"\
"<User>"\
"<id>1</id>"\
"<userName>admin</userName>"\
"<userLevel>Administrator</userLevel>"\
"</User>"\
"<User>"\
"<id>2</id>"\
"<userName>AcobaPlugin</userName>"\
"<userLevel>Operator</userLevel>"\
"</User>"\
"<User>"\
"<id>3</id>"\
"<userName>AcobaPlugin</userName>"\
"<userLevel>Operator</userLevel>"\
"</User>"\
"</UserList>"\



#define AUDIO_DATA_CONFIG_CMD "/ISAPI/System/TwoWayAudio/channels/id/audioData"

#define SET_IPSENDEVENT_CONFIG_CMD "/ISAPI/Event/notification/SetIPSendEvent"

#define UPDATE_FW_CONFIG_CMD "/ISAPI/System/updateFw"












#endif /* defs-ISAPI_H */
