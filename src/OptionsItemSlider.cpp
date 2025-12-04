#include "SmSdk/Gui/OptionsItemSlider.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

#if defined(SMSDK_ENABLE_MYGUI)

OptionsItemSlider::OptionsItemSlider(
    MyGUI::Widget* widget,
    const std::string& caption,
    float fMinValue,
    float fMaxValue,
    size_t uSteps) : OptionsItemBase(),
                     m_pSlider(nullptr),
                     m_pValueTextBox(nullptr),
                     m_uSteps(uSteps),
                     m_fMinValue(fMinValue),
                     m_fMaxValue(fMaxValue)
{
	this->initializeSlider(widget, caption);
	m_pSlider->setScrollRange(m_uSteps + 1);
}

void OptionsItemSlider::initializeSlider(MyGUI::Widget* pParent, const std::string& caption)
{
	MyGUI::LayoutManager::getInstance().loadLayout(
	    "$GAME_DATA/Gui/Layouts/Options/OptionsItem_Slider.layout", "", pParent);

	pParent->findWidget("Name")->castType<MyGUI::TextBox>()->setCaptionWithReplacing(caption);

	m_pSlider = parent->findWidget("Slider")->castType<MyGUI::ScrollBar>();
	m_pValueTextBox = parent->findWidget("Value")->castType<MyGUI::TextBox>();
}

void OptionsItemSlider::updateValueText()
{
	m_pValueTextBox->setCaption(std::to_string(m_pSlider->getScrollPosition()));
}

inline static float lerp(float a, float b, float f)
{
	return a + f * (b - a);
}

float OptionsItemSlider::getFraction() const
{
	const float fFraction = float(m_pSlider->getScrollPosition()) / float(m_uSteps);
	return lerp(m_fMinValue, m_fMaxValue, fFraction);
}

#endif