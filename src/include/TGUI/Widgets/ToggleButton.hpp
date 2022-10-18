/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2022 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_TOGGLE_BUTTON_HPP
#define TGUI_TOGGLE_BUTTON_HPP


#include <TGUI/Widgets/ButtonBase.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief ToggleButton widget
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ToggleButton : public ButtonBase
    {
    public:

        typedef std::shared_ptr<ToggleButton> Ptr; //!< Shared widget pointer
        typedef std::shared_ptr<const ToggleButton> ConstPtr; //!< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Constructor
        /// @param typeName     Type of the widget
        /// @param initRenderer Should the renderer be initialized? Should be true unless a derived class initializes it.
        /// @see create
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ToggleButton(const char* typeName = "ToggleButton", bool initRenderer = true);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new toggle button widget
        ///
        /// @param text  The text to display on the button
        /// @param down  Should the button be in down state?
        ///
        /// @return The new toggle button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ToggleButton::Ptr create(const String& text = "", bool down = false);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another toggle button
        ///
        /// @param button  The other toggle button
        ///
        /// @return The new toggle button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ToggleButton::Ptr copy(ToggleButton::ConstPtr button);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets whether the button is in down or up state
        ///
        /// @param down  Should the button be in down state?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setDown(bool down);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the button is in down or up state
        ///
        /// @return Is the button in down state?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isDown() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMouseReleased(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void keyPressed(const Event::KeyEvent& event) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves a signal based on its name
        ///
        /// @param signalName  Name of the signal
        ///
        /// @return Signal that corresponds to the name
        ///
        /// @throw Exception when the name does not match any signal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Signal& getSignal(String signalName) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget::Ptr clone() const override
        {
            return std::make_shared<ToggleButton>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        SignalBool onToggle   = {"Checked"}; //!< Button state was toggled. Optional parameter: bool containing whether the button is down or not
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TOGGLE_BUTTON_HPP

