//
//  Metabolizer.h
//  MacPuf
//
//  Created by Michael Dean on Thu Mar 07 2002.
//  Massive coding alterations done Sunday September 15, 2002.
//  Copyright (c) 2001 J. Michael Dean, M.D., M.B.A.. All rights reserved.
//
//  Abstract class that contains the frequently used damp and ph functions in MacPuf
//  All parts of MacPuf that ever use these functions will inherit from this object.
//  The gases and gsinv procedures will probably go into this class as well.

#import <Cocoa/Cocoa.h>

// Structure to return from GSINV equivalent
typedef struct _gasValues {
    float	pO2, pCO2, contO2, contCO2;
} GasValues;

// Some utility functions
float sign(float f, float g);
float abs_r(float f);		// abs function for floats


@interface Metabolizer : NSObject {
// The following fields are present in all metabolizing objects;  each object has additional
// fields that are not used here.  The following are needed for GSINV and GASES to work.
// Metabolizer is an abstract class.
    


    // Oxygen 
    float		amountOfOxygen;		
    float		pO2;			
    float		oxygenContent;		
    float		oxygenSaturation;	
    
    // Carbon dioxide
    float		amountOfCO2;		
    float		pCO2;			
    float		carbonDioxideContent;	
    
    // Bicarbonate
    float		bicarbonateContent;
    
    // pH
    float		pH;

    // structure for carrying values in and out of iterations
    GasValues		trialGases;

}
// dampChange:newValue:oldValue:dampConstant is identical to the DAMP function
// in MacPuf, and is used throughout the simulation because of the historically
// long iteration interval of 10 seconds (which the user could adjust down to 2 sec).
// I am retaining the function unless I change the entire model to use differential
// equations and Runge-Kutte estimations.  I am not likely to make this large change
// because the model works well for its educational purposes.  However, the model is
// going to be fixed at a 1.0 second interval that will not be user changeable.  The user
// will only be able to change the interval at which he or she wishes to see values
// displayed and the actual iteration used will be invisible.

//-(float)dampChange:(float)newValue: (float)oldValue: (float)dampConstant;
-(float)dampChange:(float)newValue oldValue:(float)oldValue dampConstant:(float)dampConstant;

// setPh:bicarbonate:pCO2 replaces the MacPuf function PHFNC and calculates pH from
// Henderson-Hasselbach.  This is done in all metabolizing compartments of MacPuf.

-(void)setPh;
-(void)setPh:(float)bicarbonate CO2:(float)CO2;

// The following methods return the blood gases from respective objects.  

-(float) amountOfOxygen;
-(float) pO2;
-(float) oxygenContent;
-(float) amountOfCO2;
-(float) pCO2;
-(float) carbonDioxideContent;
-(float) pH;
-(float) oxygenSaturation;
-(float) bicarbonateContent;

// The following methods are dummy methods that are needed for GASES and GSINV methods to be
// defined in the Metabolizer object.  In each of the compartments that actually use GASES or
// GSINV, these methods must be overridden.

-(void) setpO2:(float)value;
-(void) setpCO2:(float)value;
-(void) setAmountOfOxygen:(float)value;
-(void) setAmountOfCO2:(float)value;
-(void) setOxygenSaturation:(float)value;
-(void) setOxygenContent:(float)value;
-(void) setCarbonDioxideContent:(float)value;
-(void) setBicarbonateContent:(float)value;

// The following methods replace the MacPuf GASES (calcContents) and GSINV (calcPressures) subroutines
// The calcContents method receives values for partial pressures and pH and returns contents and saturation
// The calcPressures method extrapolates values for partial pressures that will yield the contents that are
// provided as parameters.
// However, for calcPressures to work it must be able to call a version of calcContents that returns trial values
// to compare in the iterations;  for this reason I have created a similar routine called calcTrialContents.  This
// differs only in that the routine returns trial values of oxygen and CO2 content (oxCont and coCont) instead of setting
// any of the compartment variables.

-(void) calcContents:(float)temperature:(float)Hct:(float)Hgb:(float)DPG;
-(GasValues) calcTrialContents:(float)temperature:(float)Hct:(float)Hgb:(float)DPG:(GasValues)trialGases;
-(void) calcPressures:(float)temperature:(float)Hct:(float)Hgb:(float)DPG;

@end
