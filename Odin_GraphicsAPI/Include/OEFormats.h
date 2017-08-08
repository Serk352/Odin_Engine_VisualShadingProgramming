#pragma once
#include "d3d11.h"

namespace OE_SDK
{

	//Texture Formats
	namespace nFormats
	{
		typedef enum eFormat
		{
			FORMAT_UNKNOWN = 0,
			FORMAT_R32G32B32A32_TYPELESS = 1,
			FORMAT_R32G32B32A32_FLOAT = 2,
			FORMAT_R32G32B32A32_UINT = 3,
			FORMAT_R32G32B32A32_SINT = 4,
			FORMAT_R32G32B32_TYPELESS = 5,
			FORMAT_R32G32B32_FLOAT = 6,
			FORMAT_R32G32B32_UINT = 7,
			FORMAT_R32G32B32_SINT = 8,
			FORMAT_R16G16B16A16_TYPELESS = 9,
			FORMAT_R16G16B16A16_FLOAT = 10,
			FORMAT_R16G16B16A16_UNORM = 11,
			FORMAT_R16G16B16A16_UINT = 12,
			FORMAT_R16G16B16A16_SNORM = 13,
			FORMAT_R16G16B16A16_SINT = 14,
			FORMAT_R32G32_TYPELESS = 15,
			FORMAT_R32G32_FLOAT = 16,
			FORMAT_R32G32_UINT = 17,
			FORMAT_R32G32_SINT = 18,
			FORMAT_R32G8X24_TYPELESS = 19,
			FORMAT_D32_FLOAT_S8X24_UINT = 20,
			FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
			FORMAT_X32_TYPELESS_G8X24_UINT = 22,
			FORMAT_R10G10B10A2_TYPELESS = 23,
			FORMAT_R10G10B10A2_UNORM = 24,
			FORMAT_R10G10B10A2_UINT = 25,
			FORMAT_R11G11B10_FLOAT = 26,
			FORMAT_R8G8B8A8_TYPELESS = 27,
			FORMAT_R8G8B8A8_UNORM = 28,
			FORMAT_R8G8B8A8_UNORM_SRGB = 29,
			FORMAT_R8G8B8A8_UINT = 30,
			FORMAT_R8G8B8A8_SNORM = 31,
			FORMAT_R8G8B8A8_SINT = 32,
			FORMAT_R16G16_TYPELESS = 33,
			FORMAT_R16G16_FLOAT = 34,
			FORMAT_R16G16_UNORM = 35,
			FORMAT_R16G16_UINT = 36,
			FORMAT_R16G16_SNORM = 37,
			FORMAT_R16G16_SINT = 38,
			FORMAT_R32_TYPELESS = 39,
			FORMAT_D32_FLOAT = 40,
			FORMAT_R32_FLOAT = 41,
			FORMAT_R32_UINT = 42,
			FORMAT_R32_SINT = 43,
			FORMAT_R24G8_TYPELESS = 44,
			FORMAT_D24_UNORM_S8_UINT = 45,
			FORMAT_R24_UNORM_X8_TYPELESS = 46,
			FORMAT_X24_TYPELESS_G8_UINT = 47,
			FORMAT_R8G8_TYPELESS = 48,
			FORMAT_R8G8_UNORM = 49,
			FORMAT_R8G8_UINT = 50,
			FORMAT_R8G8_SNORM = 51,
			FORMAT_R8G8_SINT = 52,
			FORMAT_R16_TYPELESS = 53,
			FORMAT_R16_FLOAT = 54,
			FORMAT_D16_UNORM = 55,
			FORMAT_R16_UNORM = 56,
			FORMAT_R16_UINT = 57,
			FORMAT_R16_SNORM = 58,
			FORMAT_R16_SINT = 59,
			FORMAT_R8_TYPELESS = 60,
			FORMAT_R8_UNORM = 61,
			FORMAT_R8_UINT = 62,
			FORMAT_R8_SNORM = 63,
			FORMAT_R8_SINT = 64,
			FORMAT_A8_UNORM = 65,
			FORMAT_R1_UNORM = 66,
			FORMAT_R9G9B9E5_SHAREDEXP = 67,
			FORMAT_R8G8_B8G8_UNORM = 68,
			FORMAT_G8R8_G8B8_UNORM = 69,
			FORMAT_BC1_TYPELESS = 70,
			FORMAT_BC1_UNORM = 71,
			FORMAT_BC1_UNORM_SRGB = 72,
			FORMAT_BC2_TYPELESS = 73,
			FORMAT_BC2_UNORM = 74,
			FORMAT_BC2_UNORM_SRGB = 75,
			FORMAT_BC3_TYPELESS = 76,
			FORMAT_BC3_UNORM = 77,
			FORMAT_BC3_UNORM_SRGB = 78,
			FORMAT_BC4_TYPELESS = 79,
			FORMAT_BC4_UNORM = 80,
			FORMAT_BC4_SNORM = 81,
			FORMAT_BC5_TYPELESS = 82,
			FORMAT_BC5_UNORM = 83,
			FORMAT_BC5_SNORM = 84,
			FORMAT_B5G6R5_UNORM = 85,
			FORMAT_B5G5R5A1_UNORM = 86,
			FORMAT_B8G8R8A8_UNORM = 87,
			FORMAT_B8G8R8X8_UNORM = 88,
			FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
			FORMAT_B8G8R8A8_TYPELESS = 90,
			FORMAT_B8G8R8A8_UNORM_SRGB = 91,
			FORMAT_B8G8R8X8_TYPELESS = 92,
			FORMAT_B8G8R8X8_UNORM_SRGB = 93,
			FORMAT_BC6H_TYPELESS = 94,
			FORMAT_BC6H_UF16 = 95,
			FORMAT_BC6H_SF16 = 96,
			FORMAT_BC7_TYPELESS = 97,
			FORMAT_BC7_UNORM = 98,
			FORMAT_BC7_UNORM_SRGB = 99,
			FORMAT_AYUV = 100,
			FORMAT_Y410 = 101,
			FORMAT_Y416 = 102,
			FORMAT_NV12 = 103,
			FORMAT_P010 = 104,
			FORMAT_P016 = 105,
			FORMAT_420_OPAQUE = 106,
			FORMAT_YUY2 = 107,
			FORMAT_Y210 = 108,
			FORMAT_Y216 = 109,
			FORMAT_NV11 = 110,
			FORMAT_AI44 = 111,
			FORMAT_IA44 = 112,
			FORMAT_P8 = 113,
			FORMAT_A8P8 = 114,
			FORMAT_B4G4R4A4_UNORM = 115,
			FORMAT_FORCE_UINT = 0xffffffff

		}eFormat;

		static FORCEINLINE DXGI_FORMAT	TranslateFormat(const eFormat prmFormat)
		{
			switch (prmFormat)
			{
			case nFormats::eFormat::FORMAT_UNKNOWN:
				return DXGI_FORMAT_UNKNOWN;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32A32_TYPELESS:
				return DXGI_FORMAT_R32G32B32A32_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32A32_FLOAT:
				return DXGI_FORMAT_R32G32B32A32_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32A32_UINT:
				return DXGI_FORMAT_R32G32B32A32_UINT;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32A32_SINT:
				return DXGI_FORMAT_R32G32B32A32_SINT;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32_TYPELESS:
				return DXGI_FORMAT_R32G32B32_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32_FLOAT:
				return DXGI_FORMAT_R32G32B32_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32_UINT:
				return DXGI_FORMAT_R32G32B32_UINT;
				break;
			case nFormats::eFormat::FORMAT_R32G32B32_SINT:
				return DXGI_FORMAT_R32G32B32_SINT;
				break;
			case nFormats::eFormat::FORMAT_R16G16B16A16_TYPELESS:
				return DXGI_FORMAT_R16G16B16A16_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R16G16B16A16_FLOAT:
				return DXGI_FORMAT_R16G16B16A16_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R16G16B16A16_UNORM:
				return DXGI_FORMAT_R16G16B16A16_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R16G16B16A16_UINT:
				return DXGI_FORMAT_R16G16B16A16_UINT;
				break;
			case nFormats::eFormat::FORMAT_R16G16B16A16_SNORM:
				return DXGI_FORMAT_R16G16B16A16_SNORM;
				break;
			case nFormats::eFormat::FORMAT_R16G16B16A16_SINT:
				return DXGI_FORMAT_R16G16B16A16_SINT;
				break;
			case nFormats::eFormat::FORMAT_R32G32_TYPELESS:
				return DXGI_FORMAT_R32G32_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R32G32_FLOAT:
				return DXGI_FORMAT_R32G32_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R32G32_UINT:
				return DXGI_FORMAT_R32G32_UINT;
				break;
			case nFormats::eFormat::FORMAT_R32G32_SINT:
				return DXGI_FORMAT_R32G32_SINT;
				break;
			case nFormats::eFormat::FORMAT_R32G8X24_TYPELESS:
				return DXGI_FORMAT_R32G8X24_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_D32_FLOAT_S8X24_UINT:
				return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
				break;
			case nFormats::eFormat::FORMAT_R32_FLOAT_X8X24_TYPELESS:
				return DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_X32_TYPELESS_G8X24_UINT:
				return DXGI_FORMAT_X32_TYPELESS_G8X24_UINT;
				break;
			case nFormats::eFormat::FORMAT_R10G10B10A2_TYPELESS:
				return DXGI_FORMAT_R10G10B10A2_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R10G10B10A2_UNORM:
				return DXGI_FORMAT_R10G10B10A2_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R10G10B10A2_UINT:
				return DXGI_FORMAT_R10G10B10A2_UINT;
				break;
			case nFormats::eFormat::FORMAT_R11G11B10_FLOAT:
				return DXGI_FORMAT_R11G11B10_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R8G8B8A8_TYPELESS:
				return DXGI_FORMAT_R8G8B8A8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R8G8B8A8_UNORM:
				return DXGI_FORMAT_R8G8B8A8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R8G8B8A8_UNORM_SRGB:
				return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_R8G8B8A8_UINT:
				return DXGI_FORMAT_R8G8B8A8_UINT;
				break;
			case nFormats::eFormat::FORMAT_R8G8B8A8_SNORM:
				return DXGI_FORMAT_R8G8B8A8_SNORM;
				break;
			case nFormats::eFormat::FORMAT_R8G8B8A8_SINT:
				return DXGI_FORMAT_R8G8B8A8_SINT;
				break;
			case nFormats::eFormat::FORMAT_R16G16_TYPELESS:
				return DXGI_FORMAT_R16G16_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R16G16_FLOAT:
				return DXGI_FORMAT_R16G16_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R16G16_UNORM:
				return DXGI_FORMAT_R16G16_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R16G16_UINT:
				return DXGI_FORMAT_R16G16_UINT;
				break;
			case nFormats::eFormat::FORMAT_R16G16_SNORM:
				return DXGI_FORMAT_R16G16_SNORM;
				break;
			case nFormats::eFormat::FORMAT_R16G16_SINT:
				return DXGI_FORMAT_R16G16_SINT;
				break;
			case nFormats::eFormat::FORMAT_R32_TYPELESS:
				return DXGI_FORMAT_R32_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_D32_FLOAT:
				return DXGI_FORMAT_D32_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R32_FLOAT:
				return DXGI_FORMAT_R32_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_R32_UINT:
				return DXGI_FORMAT_R32_UINT;
				break;
			case nFormats::eFormat::FORMAT_R32_SINT:
				return DXGI_FORMAT_R32_SINT;
				break;
			case nFormats::eFormat::FORMAT_R24G8_TYPELESS:
				return DXGI_FORMAT_R24G8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_D24_UNORM_S8_UINT:
				return DXGI_FORMAT_D24_UNORM_S8_UINT;
				break;
			case nFormats::eFormat::FORMAT_R24_UNORM_X8_TYPELESS:
				return DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_X24_TYPELESS_G8_UINT:
				return DXGI_FORMAT_X24_TYPELESS_G8_UINT;
				break;
			case nFormats::eFormat::FORMAT_R8G8_TYPELESS:
				return DXGI_FORMAT_R8G8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R8G8_UNORM:
				return DXGI_FORMAT_R8G8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R8G8_UINT:
				return DXGI_FORMAT_R8G8_UINT;
				break;
			case nFormats::eFormat::FORMAT_R8G8_SNORM:
				return DXGI_FORMAT_R8G8_SNORM;
				break;
			case nFormats::eFormat::FORMAT_R8G8_SINT:
				return DXGI_FORMAT_R8G8_SINT;
				break;
			case nFormats::eFormat::FORMAT_R16_TYPELESS:
				return DXGI_FORMAT_R16_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R16_FLOAT:
				return DXGI_FORMAT_R16_FLOAT;
				break;
			case nFormats::eFormat::FORMAT_D16_UNORM:
				return DXGI_FORMAT_D16_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R16_UNORM:
				return DXGI_FORMAT_R16_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R16_UINT:
				return DXGI_FORMAT_R16_UINT;
				break;
			case nFormats::eFormat::FORMAT_R16_SNORM:
				return DXGI_FORMAT_R16_SNORM;
				break;
			case nFormats::eFormat::FORMAT_R16_SINT:
				return DXGI_FORMAT_R16_SINT;
				break;
			case nFormats::eFormat::FORMAT_R8_TYPELESS:
				return DXGI_FORMAT_R8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_R8_UNORM:
				return DXGI_FORMAT_R8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R8_UINT:
				return DXGI_FORMAT_R8_UINT;
				break;
			case nFormats::eFormat::FORMAT_R8_SNORM:
				return DXGI_FORMAT_R8_SNORM;
				break;
			case nFormats::eFormat::FORMAT_R8_SINT:
				return DXGI_FORMAT_R8_SINT;
				break;
			case nFormats::eFormat::FORMAT_A8_UNORM:
				return DXGI_FORMAT_A8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R1_UNORM:
				return DXGI_FORMAT_R1_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R9G9B9E5_SHAREDEXP:
				return DXGI_FORMAT_R9G9B9E5_SHAREDEXP;
				break;
			case nFormats::eFormat::FORMAT_R8G8_B8G8_UNORM:
				return DXGI_FORMAT_R8G8_B8G8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_G8R8_G8B8_UNORM:
				return DXGI_FORMAT_G8R8_G8B8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC1_TYPELESS:
				return DXGI_FORMAT_BC1_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC1_UNORM:
				return DXGI_FORMAT_BC1_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC1_UNORM_SRGB:
				return DXGI_FORMAT_BC1_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_BC2_TYPELESS:
				return DXGI_FORMAT_BC2_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC2_UNORM:
				return DXGI_FORMAT_BC2_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC2_UNORM_SRGB:
				return DXGI_FORMAT_BC2_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_BC3_TYPELESS:
				return DXGI_FORMAT_BC3_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC3_UNORM:
				return DXGI_FORMAT_BC3_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC3_UNORM_SRGB:
				return DXGI_FORMAT_BC3_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_BC4_TYPELESS:
				return DXGI_FORMAT_BC4_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC4_UNORM:
				return DXGI_FORMAT_BC4_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC4_SNORM:
				return DXGI_FORMAT_BC4_SNORM;
				break;
			case nFormats::eFormat::FORMAT_BC5_TYPELESS:
				return DXGI_FORMAT_BC5_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC5_UNORM:
				return DXGI_FORMAT_BC5_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC5_SNORM:
				return DXGI_FORMAT_BC5_SNORM;
				break;
			case nFormats::eFormat::FORMAT_B5G6R5_UNORM:
				return DXGI_FORMAT_B5G6R5_UNORM;
				break;
			case nFormats::eFormat::FORMAT_B5G5R5A1_UNORM:
				return DXGI_FORMAT_B5G5R5A1_UNORM;
				break;
			case nFormats::eFormat::FORMAT_B8G8R8A8_UNORM:
				return DXGI_FORMAT_B8G8R8A8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_B8G8R8X8_UNORM:
				return DXGI_FORMAT_B8G8R8X8_UNORM;
				break;
			case nFormats::eFormat::FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
				return DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM;
				break;
			case nFormats::eFormat::FORMAT_B8G8R8A8_TYPELESS:
				return DXGI_FORMAT_B8G8R8A8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_B8G8R8A8_UNORM_SRGB:
				return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_B8G8R8X8_TYPELESS:
				return DXGI_FORMAT_B8G8R8X8_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_B8G8R8X8_UNORM_SRGB:
				return DXGI_FORMAT_B8G8R8X8_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_BC6H_TYPELESS:
				return DXGI_FORMAT_BC6H_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC6H_UF16:
				return DXGI_FORMAT_BC6H_UF16;
				break;
			case nFormats::eFormat::FORMAT_BC6H_SF16:
				return DXGI_FORMAT_BC6H_SF16;
				break;
			case nFormats::eFormat::FORMAT_BC7_TYPELESS:
				return DXGI_FORMAT_BC7_TYPELESS;
				break;
			case nFormats::eFormat::FORMAT_BC7_UNORM:
				return DXGI_FORMAT_BC7_UNORM;
				break;
			case nFormats::eFormat::FORMAT_BC7_UNORM_SRGB:
				return DXGI_FORMAT_BC7_UNORM_SRGB;
				break;
			case nFormats::eFormat::FORMAT_AYUV:
				return DXGI_FORMAT_AYUV;
				break;
			case nFormats::eFormat::FORMAT_Y410:
				return DXGI_FORMAT_Y410;
				break;
			case nFormats::eFormat::FORMAT_Y416:
				return DXGI_FORMAT_Y416;
				break;
			case nFormats::eFormat::FORMAT_NV12:
				return DXGI_FORMAT_NV12;
				break;
			case nFormats::eFormat::FORMAT_P010:
				return DXGI_FORMAT_P010;
				break;
			case nFormats::eFormat::FORMAT_P016:
				return DXGI_FORMAT_P016;
				break;
			case nFormats::eFormat::FORMAT_420_OPAQUE:
				return DXGI_FORMAT_420_OPAQUE;
				break;
			case nFormats::eFormat::FORMAT_YUY2:
				return DXGI_FORMAT_YUY2;
				break;
			case nFormats::eFormat::FORMAT_Y210:
				return DXGI_FORMAT_Y210;
				break;
			case nFormats::eFormat::FORMAT_Y216:
				return DXGI_FORMAT_Y216;
				break;
			case nFormats::eFormat::FORMAT_NV11:
				return DXGI_FORMAT_NV11;
				break;
			case nFormats::eFormat::FORMAT_AI44:
				return DXGI_FORMAT_AI44;
				break;
			case nFormats::eFormat::FORMAT_IA44:
				return DXGI_FORMAT_IA44;
				break;
			case nFormats::eFormat::FORMAT_P8:
				return DXGI_FORMAT_P8;
				break;
			case nFormats::eFormat::FORMAT_A8P8:
				return DXGI_FORMAT_A8P8;
				break;
			case nFormats::eFormat::FORMAT_B4G4R4A4_UNORM:
				return DXGI_FORMAT_B4G4R4A4_UNORM;
				break;
			case nFormats::eFormat::FORMAT_FORCE_UINT:
				return DXGI_FORMAT_FORCE_UINT;
				break;

			default:
				return DXGI_FORMAT_UNKNOWN;
				break;
			}
		}
	}

	//Bind Flags
	namespace nBindFlags
	{
		typedef enum eBindFlag
		{
			BIND_VERTEX_BUFFER = 0x1L,
			BIND_INDEX_BUFFER = 0x2L,
			BIND_CONSTANT_BUFFER = 0x4L,
			BIND_SHADER_RESOURCE = 0x8L,
			BIND_STREAM_OUTPUT = 0x10L,
			BIND_RENDER_TARGET = 0x20L,
			BIND_DEPTH_STENCIL = 0x40L,
			BIND_UNORDERED_ACCESS = 0x80L,
			BIND_DECODER = 0x200L,
			BIND_VIDEO_ENCODER = 0x400L

		}eBindflag;

		static FORCEINLINE D3D11_BIND_FLAG TranslateBindFlag(eBindFlag prmBindingFlag)
		{
			switch (prmBindingFlag)
			{
			case eBindFlag::BIND_VERTEX_BUFFER:
				return D3D11_BIND_VERTEX_BUFFER;
				break;
			case eBindFlag::BIND_INDEX_BUFFER:
				return D3D11_BIND_INDEX_BUFFER;
				break;
			case eBindFlag::BIND_CONSTANT_BUFFER:
				return D3D11_BIND_CONSTANT_BUFFER;
				break;
			case eBindFlag::BIND_SHADER_RESOURCE:
				return D3D11_BIND_SHADER_RESOURCE;
				break;
			case eBindFlag::BIND_STREAM_OUTPUT:
				return D3D11_BIND_STREAM_OUTPUT;
				break;
			case eBindFlag::BIND_RENDER_TARGET:
				return D3D11_BIND_RENDER_TARGET;
				break;
			case eBindFlag::BIND_DEPTH_STENCIL:
				return D3D11_BIND_DEPTH_STENCIL;
				break;
			case eBindFlag::BIND_UNORDERED_ACCESS:
				return D3D11_BIND_UNORDERED_ACCESS;
				break;
			case eBindFlag::BIND_DECODER:
				return D3D11_BIND_DECODER;
				break;
			case eBindFlag::BIND_VIDEO_ENCODER:
				return D3D11_BIND_VIDEO_ENCODER;
				break;
			default:
				return D3D11_BIND_VERTEX_BUFFER;
				break;
			}

		}
	}

	//Sampling Filters
	namespace nSamplingFilters
	{
		typedef enum eSamplingFilter
		{
			FILTER_MIN_MAG_MIP_POINT = 0,
			FILTER_MIN_MAG_POINT_MIP_LINEAR = 0x1,
			FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x4,
			FILTER_MIN_POINT_MAG_MIP_LINEAR = 0x5,
			FILTER_MIN_LINEAR_MAG_MIP_POINT = 0x10,
			FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
			FILTER_MIN_MAG_LINEAR_MIP_POINT = 0x14,
			FILTER_MIN_MAG_MIP_LINEAR = 0x15,
			FILTER_ANISOTROPIC = 0x55,
			FILTER_COMPARISON_MIN_MAG_MIP_POINT = 0x80,
			FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = 0x81,
			FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x84,
			FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = 0x85,
			FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = 0x90,
			FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
			FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 0x94,
			FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 0x95,
			FILTER_COMPARISON_ANISOTROPIC = 0xd5,
			FILTER_MINIMUM_MIN_MAG_MIP_POINT = 0x100,
			FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x101,
			FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x104,
			FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x105,
			FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x110,
			FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x111,
			FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x114,
			FILTER_MINIMUM_MIN_MAG_MIP_LINEAR = 0x115,
			FILTER_MINIMUM_ANISOTROPIC = 0x155,
			FILTER_MAXIMUM_MIN_MAG_MIP_POINT = 0x180,
			FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x181,
			FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x184,
			FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x185,
			FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x190,
			FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x191,
			FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x194,
			FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR = 0x195,
			FILTER_MAXIMUM_ANISOTROPIC = 0x1d5
		}eSamplingFilter;
		static FORCEINLINE D3D11_FILTER TranslateFilter(const eSamplingFilter myFilter)
		{
			switch (myFilter)
			{
			case eSamplingFilter::FILTER_MIN_MAG_MIP_POINT:
				return D3D11_FILTER_MIN_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MIN_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MIN_POINT_MAG_MIP_LINEAR:
				return D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MIN_LINEAR_MAG_MIP_POINT:
				return D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MIN_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MIN_MAG_MIP_LINEAR:
				return D3D11_FILTER_MIN_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_ANISOTROPIC:
				return D3D11_FILTER_ANISOTROPIC;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_MAG_MIP_POINT:
				return D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR:
				return D3D11_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT:
				return D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_COMPARISON_MIN_MAG_MIP_LINEAR:
				return D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_COMPARISON_ANISOTROPIC:
				return D3D11_FILTER_COMPARISON_ANISOTROPIC;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_MAG_MIP_POINT:
				return D3D11_FILTER_MINIMUM_MIN_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR:
				return D3D11_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT:
				return D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MINIMUM_MIN_MAG_MIP_LINEAR:
				return D3D11_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MINIMUM_ANISOTROPIC:
				return D3D11_FILTER_MINIMUM_ANISOTROPIC;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_MAG_MIP_POINT:
				return D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR:
				return D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT:
				return D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
				return D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT:
				return D3D11_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR:
				return D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR;
				break;
			case eSamplingFilter::FILTER_MAXIMUM_ANISOTROPIC:
				return D3D11_FILTER_MAXIMUM_ANISOTROPIC;
				break;
			default:
				return D3D11_FILTER_MIN_MAG_MIP_POINT; 
				break;

			}
		}

	}

	//Texture Addres Mode

	namespace nTextureAddresModes
	{
		typedef enum eTextureAddresMode 
		{
			TEXTURE_ADDRESS_WRAP = 1,
			TEXTURE_ADDRESS_MIRROR = 2,
			TEXTURE_ADDRESS_CLAMP = 3,
			TEXTURE_ADDRESS_BORDER = 4,
			TEXTURE_ADDRESS_MIRROR_ONCE = 5
		}eTextureAddresMode;
		static FORCEINLINE D3D11_TEXTURE_ADDRESS_MODE TranslateTextureAddressMode(const eTextureAddresMode myAddresMode)
		{
			switch (myAddresMode)
			{


			case eTextureAddresMode::TEXTURE_ADDRESS_WRAP:
				return D3D11_TEXTURE_ADDRESS_WRAP;
				break;

			case eTextureAddresMode::TEXTURE_ADDRESS_MIRROR:
				return D3D11_TEXTURE_ADDRESS_MIRROR;
				break;

			case eTextureAddresMode::TEXTURE_ADDRESS_CLAMP:
				return D3D11_TEXTURE_ADDRESS_CLAMP;
				break;

			case eTextureAddresMode::TEXTURE_ADDRESS_BORDER:
				return D3D11_TEXTURE_ADDRESS_BORDER;
				break;

			case eTextureAddresMode::TEXTURE_ADDRESS_MIRROR_ONCE:
				return D3D11_TEXTURE_ADDRESS_MIRROR_ONCE;
				break;

			default:
				return D3D11_TEXTURE_ADDRESS_WRAP;
				break;

			}
		}

	}

	//Comparison Functions
	namespace nComparisonFunctions
	{
		typedef enum eComparisonFunc 
		{
			COMPARISON_NEVER = 1,
			COMPARISON_LESS = 2,
			COMPARISON_EQUAL = 3,
			COMPARISON_LESS_EQUAL = 4,
			COMPARISON_GREATER = 5,
			COMPARISON_NOT_EQUAL = 6,
			COMPARISON_GREATER_EQUAL = 7,
			COMPARISON_ALWAYS = 8
		}ComparisonFunc;
		static FORCEINLINE D3D11_COMPARISON_FUNC TranslateComparisonFunc(eComparisonFunc myCompFunc)
		{
			switch (myCompFunc)
			{
			case eComparisonFunc::COMPARISON_NEVER:
				return D3D11_COMPARISON_NEVER;
				break;
			case eComparisonFunc::COMPARISON_LESS:
				return D3D11_COMPARISON_LESS;
				break;
			case eComparisonFunc::COMPARISON_EQUAL:
				return D3D11_COMPARISON_EQUAL;
				break;
			case eComparisonFunc::COMPARISON_LESS_EQUAL:
				return D3D11_COMPARISON_LESS_EQUAL;
				break;
			case eComparisonFunc::COMPARISON_GREATER:
				return D3D11_COMPARISON_GREATER;
				break;
			case eComparisonFunc::COMPARISON_NOT_EQUAL:
				return D3D11_COMPARISON_NOT_EQUAL;
				break;
			case eComparisonFunc::COMPARISON_GREATER_EQUAL:
				return D3D11_COMPARISON_GREATER_EQUAL;
				break;
			case eComparisonFunc::COMPARISON_ALWAYS:
				return D3D11_COMPARISON_ALWAYS;
				break;
			default:
				return D3D11_COMPARISON_NEVER;
				break;
			}
		}

	}

	//Usage Flag
	namespace nUsageFlags
	{
		typedef enum eUsageFlag 
		{
			USAGE_DEFAULT = 0,
			USAGE_IMMUTABLE = 1,
			USAGE_DYNAMIC = 2,
			USAGE_STAGING = 3
		}eUsageFlag;

		static FORCEINLINE D3D11_USAGE TranslateUFlag(eUsageFlag  prmUFlag) 
		{
			switch (prmUFlag)
			{
				case eUsageFlag::USAGE_DEFAULT:
					return D3D11_USAGE_DEFAULT;
					break;
				case eUsageFlag::USAGE_IMMUTABLE:
					return D3D11_USAGE_IMMUTABLE;
					break;
				case eUsageFlag::USAGE_DYNAMIC:
					return D3D11_USAGE_DYNAMIC;
					break;
				case eUsageFlag::USAGE_STAGING:
					return D3D11_USAGE_STAGING;
					break;
				default:
					return D3D11_USAGE_DEFAULT;
					break;
			}
		}


	}

	namespace nResourceType
	{
		typedef enum eResourceType
		{
			TEXTURE_2D = 0,
			SHADER = 1
		}eResourceType;
	}
}
