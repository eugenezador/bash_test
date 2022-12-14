#!/bin/bash

bluetoothctl power on

TRUE="1"

DEVICE_NAME="EW10"

MAC_HEADSET=$(bt-device -l | grep $DEVICE_NAME | grep -o "[[:xdigit:]:]\{11,17\}")

CONNECTED=$(bt-device -i $MAC_HEADSET | grep Connected | awk '{print $2}') 

PAIRED=$(bt-device -i $MAC_HEADSET | grep Paired | awk '{print $2}')

if [ $PAIRED = $TRUE ]
then
	if [ $CONNECTED = $TRUE ]
	then
		if [ $(pacmd list-sinks | grep '  index' | cut -f6 -d' ') != $TRUE ] 
		then
			HEADSET_INDEX=$(pacmd list-sinks | grep '  index' | cut -f6 -d' ')
			pacmd set-default-sink $HEADSET_INDEX
		fi
	fi
else
	bluetoothctl pair $MAC_HEADSET
fi

exit
