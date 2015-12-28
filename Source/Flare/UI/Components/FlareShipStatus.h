#pragma once

#include "../../Flare.h"
#include "../../Spacecrafts/FlareSpacecraftInterface.h"


class SFlareShipStatus : public SCompoundWidget
{
	/*----------------------------------------------------
		Slate arguments
	----------------------------------------------------*/

	SLATE_BEGIN_ARGS(SFlareShipStatus)
		: _Ship(NULL)
		, _Center(false)
	{}

	SLATE_ARGUMENT(IFlareSpacecraftInterface*, Ship)
	SLATE_ARGUMENT(bool, Center)
	
	SLATE_END_ARGS()


public:

	/*----------------------------------------------------
		Public methods
	----------------------------------------------------*/

	/** Create the widget */
	void Construct(const FArguments& InArgs);

	/** Set the ship to display data for */
	void SetTargetShip(IFlareSpacecraftInterface* Target);


protected:

	/*----------------------------------------------------
		Callbacks
	----------------------------------------------------*/

	/** Mouse entered (tooltip) */
	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	/** Mouse left (tooltip) */
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;

	/** Get the current color */
	FSlateColor GetIconColor(EFlareSubsystem::Type Type) const;


protected:

	/*----------------------------------------------------
		Private data
	----------------------------------------------------*/

	// Ship data
	IFlareSpacecraftInterface*                    TargetShip;
	bool                                    CenterIcons;

	// Slate data
	TSharedPtr<SImage>                      WeaponIndicator;


};
