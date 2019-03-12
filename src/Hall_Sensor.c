#include "Hall_Sensor.h"
#include "Ram.h"

/*****************************************************************************
Name:          SR_I16Filter
 Parameters:    I16* lpi16Data      -> Instantaneus Data Address
                I32* lpi32ShiftAdd  -> Sum of Previous data and Instantaneus Data Address
                I16* lpi16Result    -> Filter Result Address
Returns:       None
Called by:     SR_ProcessSensor( )
Calls:         None
Description:   Filters a signed 16 bit variable using a 31:1 ratio from the current
                average vs the new sample value.
                Used to filter the temperature

********************************************************************************/
void SR_I16Filter(uint16_t *lpi16Data, uint32_t *lpi32ShiftAdd, uint16_t *lpi16Result)
{
    uint32_t li32InstantData;
    uint32_t li32Temporal;

    li32InstantData = ((uint32_t)(*lpi16Data) * 0x80);                      // Scale Instantaneous data by 128
    li32Temporal    = li32InstantData + (511 * (*lpi32ShiftAdd));           // Add Weighted Scaled Instantaneous data with Weighted Scaled Average Data
    *lpi32ShiftAdd  = (li32Temporal / 512);                                 // Get new Scaled Average data
    *lpi16Result    = (uint16_t)( *lpi32ShiftAdd / 0x80 );                  // UnScale Average Data
}

/*****************************************************************************
Name:          SR_InitFilter
Parameters:    struct stFilterParameters *lpstFilterParam
                lu16FilterCoef
Returns:       none
Called by:
 Calls:         none
Description:   Initilizes the filter parameters
******************************************************************************/
void SR_InitFilter(uint16_t li16InputData)
{
    i16InputVar        = li16InputData;
    i32VarAccumulator  = (uint32_t) li16InputData * 0x80;      // Scale the variable by 128 and save to internal filter average
    i16AverageVar      = li16InputData;                        // Average Instantaneous variable
}
