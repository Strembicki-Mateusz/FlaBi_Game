/******************************************************************************
* Copyright (c) 2018(-2023) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.21.3 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

/**
 * @file touchgfx/Drawable.hpp
 *
 * Declares the touchgfx::Drawable class.
 */
#ifndef TOUCHGFX_VIDEOCONTROLLER_HPP
#define TOUCHGFX_VIDEOCONTROLLER_HPP

#include <touchgfx/hal/Types.hpp>

namespace touchgfx
{
/**
 * This type contains various information read from a video file.
 */
struct VideoInformation
{
    uint32_t ms_between_frames; ///< The number of milliseconds between frames
    uint32_t number_of_frames;  ///< The number of frames in the movie
    uint32_t frame_width;       ///< The frame width in pixels
    uint32_t frame_height;      ///< The frame height in pixels
};

/** Interface for classes reading video data from non-memory-mapped flash storage. */
class VideoDataReader
{
public:
    /** Virtual destructor. */
    virtual ~VideoDataReader()
    {
    }

    /**
     * Get the length of the data (file).
     *
     * @return  The length of the data.
     */
    virtual uint32_t getDataLength() = 0;

    /**
     * Seek to a specific position in the data (file).
     *
     * @param   position    Byte position in the data that is needed next.
     */
    virtual void seek(uint32_t position) = 0;

    /**
     * Read data from flash to a buffer. This must be a synchrony method that does not return until
     * the copy is done.
     *
     * @param [in,out]  dst     Address of destination buffer in RAM.
     * @param           bytes   Number of bytes to copy.
     *
     * @return  Returns true if read was successful.
     */
    virtual bool readData(void* dst, uint32_t bytes) = 0;
};

class VideoWidget;

/**
 * The VideoController is an abstract interface for the video decoder. A
 * concrete implementation will be generated by the TouchGFX
 * Generator.
 *
 * The VideoController can control multiple video streams in multiple
 * VideoWidgets. These are recognized by their Handle.
 *
 * Application code should only interact with the VideoWidget class.
 *
 * @see VideoWidget
 */
class VideoController
{
public:
    /** The commands send to the Controller. */
    enum Command
    {
        PLAY,      ///< Play the video
        PAUSE,     ///< Pause the playing
        SEEK,      ///< Seek to frame
        SHOW,      ///< Show a frame
        STOP,      ///< Stop the video
        SET_REPEAT ///< Set repeat mode
    };

    /** Virtual destructor. */
    virtual ~VideoController()
    {
    }

    /** Type to identify a video stream. */
    typedef uint32_t Handle;

    /**
     * Gets the VideoController instance.
     *
     * @return  The VideoController instance.
     */
    static VideoController& getInstance();

    /**
     * Register a VideoWidget to get a Handle.
     *
     * @param [in,out]  widget  The VideoWidget.
     *
     * @return  A video stream handle.
     */
    virtual Handle registerVideoWidget(VideoWidget& widget) = 0;

    /**
     * Unregister a VideoWidget to release the handle.
     *
     * @param   handle  The stream handle.
     */
    virtual void unregisterVideoWidget(const Handle handle) = 0;

    /**
     * Set the framerate for video using a qoutient of screen frames /video frames.
     *
     * To get 20 video frames pr second on a 60 fps display use video_frames = 20 and ui_frames = 60.
     *
     * @param   handle          The stream handle.
     * @param   ui_frames       Number of UI frames (divider)
     * @param   video_frames    Number of video_frames (dividend)
     */
    virtual void setFrameRate(const Handle handle, uint32_t ui_frames, uint32_t video_frames) = 0;

    /**
     * Signal that the widget can be invalidated (tickEvent).
     *
     * @param           handle  The stream handle.
     * @param [in,out]  widget  The Widget.
     *
     * @return  Returns true if video has more frames (i.e. false on the last frame).
     */
    virtual bool updateFrame(const Handle handle, VideoWidget& widget) = 0;

    /**
     * Draw the video content.
     *
     * @param   handle          The stream handle.
     * @param   invalidatedArea The area of the widget that must be redrawn.
     * @param   widget          Reference to the widget.
     */
    virtual void draw(const Handle handle, const Rect& invalidatedArea, const VideoWidget& widget) = 0;

    /**
     * Set the video data for the stream.
     *
     * @param   handle  The stream handle.
     * @param   movie   Pointer to the video data.
     * @param   length  Length of the video data.
     */
    virtual void setVideoData(const Handle handle, const uint8_t* movie, const uint32_t length) = 0;

    /**
     * Set the video data for the stream.
     *
     * @param           handle  The stream handle.
     * @param [in,out]  reader  Reference to a VideoDataReader object.
     */
    virtual void setVideoData(const Handle handle, VideoDataReader& reader) = 0;

    /**
     * Pass a command from the Widget to the Controller.
     *
     * @param   handle  The stream handle.
     * @param   cmd     The Command.
     * @param   param   A parameter.
     */
    virtual void setCommand(const Handle handle, Command cmd, uint32_t param) = 0;

    /**
     * Get the current frame number.
     *
     * @param   handle  The stream handle.
     *
     * @return  Return the current frame number.
     */
    virtual uint32_t getCurrentFrameNumber(const Handle handle) = 0;

    /**
     * Get Video information.
     *
     * Get information from the video data.
     *
     * @param           handle  The stream handle.
     * @param [in,out]  data    Pointer to VideoInformation where information should be stored.
     */
    virtual void getVideoInformation(const Handle handle, VideoInformation* data) = 0;

    /**
     * Check if the video stream is playing (not paused or stopped).
     *
     * @param   handle  The stream handle.
     *
     * @return  Returns true if the video is playing.
     */
    virtual bool getIsPlaying(const Handle handle) = 0;
};

} // namespace touchgfx

#endif // TOUCHGFX_VIDEOCONTROLLER_HPP
