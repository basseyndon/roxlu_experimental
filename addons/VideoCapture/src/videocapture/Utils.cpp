#include <videocapture/Utils.h>

std::string rx_libav_pixel_format_to_string(enum AVPixelFormat fmt) {
  switch(fmt) {
    case AV_PIX_FMT_ARGB: return "AV_PIX_FMT_ARGB"; break;        
    case AV_PIX_FMT_BGRA: return "AV_PIX_FMT_BGRA"; break;           
    case AV_PIX_FMT_RGB24: return "AV_PIX_FMT_RGB24"; break;          
    case AV_PIX_FMT_RGB555BE: return "AV_PIX_FMT_RGB555BE"; break;       
    case AV_PIX_FMT_RGB565BE: return "AV_PIX_FMT_RGB565BE"; break;       
    case AV_PIX_FMT_RGB555LE: return "AV_PIX_FMT_RGB555LE"; break;       
    case AV_PIX_FMT_RGB565LE: return "AV_PIX_FMT_RGB565LE"; break;       
    case AV_PIX_FMT_YUYV422: return "AV_PIX_FMT_YUYV422"; break;        
    case AV_PIX_FMT_UYVY422: return "AV_PIX_FMT_UYVY422"; break;        
    case AV_PIX_FMT_YUV444P: return "AV_PIX_FMT_YUV444P"; break;        
    case AV_PIX_FMT_YUV444P16LE: return "AV_PIX_FMT_YUV444P16LE"; break;    
    case AV_PIX_FMT_YUV422P16LE: return "AV_PIX_FMT_YUV422P16LE"; break;    
    case AV_PIX_FMT_YUV422P10LE: return "AV_PIX_FMT_YUV422P10LE"; break;    
    case AV_PIX_FMT_YUV444P10LE: return "AV_PIX_FMT_YUV444P10LE"; break;    
    default: return "UNHANDLED AVPIXELFORMAT. ";
  };
}


