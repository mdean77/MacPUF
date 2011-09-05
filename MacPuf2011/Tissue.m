//
//  Tissue.m
//  MacPuf
//
//  Created by J. Michael Dean on Wed Mar 06 2002. And extra shit added in 2008.
//  Massive coding alterations done Sunday September 15, 2002.
//  More massive coding changes between December and February, 2003
//  Copyright (c) 2002 - 2003 J.Michael Dean, M.D., M.B.A. All rights reserved.
//

#import "Tissue.h"


@implementation Tissue

-(id) init
{
    NSLog(@"Creating %@", self);    
    if (self = [super init]) {
        amountOfOxygen = 177.4896;
        pO2 = 39.9351;
        oxygenContent = 14.4212; 
        oxygenSaturation = 0;  // Value made up - needs to be connected to simulator
        amountOfCO2 = 13.3736;
        pCO2 = 45.4757;
        carbonDioxideContent = 51.4988;
        pN2 = 571.2808;
        amountOfNitrogen = 76.1708;
        slowN2 = 570.0273;
        amountSlowNitrogen = 977.1898; 
        excessNitrogen = 0.000;
        bicarbonateContent = 25.5284;
        bicarbonateAmount = 317.5415;
        lactateAmount = 34.7917;
        pH = 7.3721;
        oxygenConsumption = 240.000;
        respiratoryQuotient = 0.8000;
        extraFluidVolume = 12.0000;
        bubbles = 0.000;
        referenceCO2 = -0.2543;
        TC3AJ = -0.0677;
        NSLog(@"Object initialized: %@", self);
        }
    return self;
}

-(NSString *) description
{
    return [NSString stringWithFormat:
            @"\nTissue/ECF%7.1f%8.1f%8.1f%8.1f%8.0f%8.0f%7.3f%6.1f",
            pO2, pCO2,oxygenContent, carbonDioxideContent,amountOfOxygen,amountOfCO2*1000,pH,
            bicarbonateContent];
}

// Accessors
-(float) oxygenConsumption
{
    return oxygenConsumption;
}

-(float) respiratoryQuotient
{
    return respiratoryQuotient;
}

-(float) extraFluidVolume
{
    return extraFluidVolume;
}

-(float) pN2 {
    return pN2;
}

-(float) amountOfNitrogen {
    return amountOfNitrogen;
}

-(float) slowN2 {
    return slowN2;
}

-(float) amountSlowNitrogen {
    return amountSlowNitrogen;
}

-(float) excessNitrogen {
    return excessNitrogen;
}

-(float) lactateAmount {
    return lactateAmount;
}

-(float) bubbles {
    return bubbles;
}

-(float) referenceCO2 {
    return referenceCO2;
}

-(float) TC3AJ {
    return TC3AJ;
}
- (float)bicarbonateAmount
{
    return bicarbonateAmount;
}

-(void) setOxygenConsumption:(float)value
{
    oxygenConsumption = value;
}

-(void) setRespiratoryQuotient:(float)value
{
    respiratoryQuotient = value;
}

-(void) setExtraFluidVolume:(float)value
{
    extraFluidVolume = value;
}

-(void) setpN2:(float)value {
    pN2 = value;
}

-(void) setAmountOfNitrogen:(float)value {
    amountOfNitrogen = value;
}

-(void) setSlowN2:(float)value {
    slowN2 = value;
}

-(void) setAmountSlowNitrogen:(float)value {
    amountSlowNitrogen = value;
}

-(void) setExcessNitrogen:(float)value {
    excessNitrogen = value;
}

-(void) setLactateAmount:(float)value {
    lactateAmount = value;
}

-(void) setBubbles:(float)value {
    bubbles = value;
}

-(void) setReferenceCO2:(float)value {
    referenceCO2 = value;
}

-(void) setTC3AJ:(float)value {
    TC3AJ = value;
}

    - (void)setBicarbonateAmount:(float)newAmountBicarbonate
{
    bicarbonateAmount = newAmountBicarbonate;
}
@end
