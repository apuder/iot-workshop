
# http://www.imagemagick.org/Usage/thumbnails/

IMAGES = Arduino_Terminal-th.png Finish-th.png Terminal-th.png \
         Board_Manager-th.png Notification-th.png maker-th.png \
         ChooseAction-th.png Port_Setting-th.png that-th.png \
         CompleteActionField-th.png Preferences-th.png webhook-th.png \
         CreateTrigger-th.png Request-th.png

%-th.png: %.jpg
	convert -define jpeg:size=500x180 $< -auto-orient \
	           -thumbnail 250x90 -unsharp 0x.5 tmp.jpg
	convert tmp.jpg \
           -format 'roundrectangle 1,1 %[fx:w+4],%[fx:h+4] 15,15' \
           -write info:tmp.mvg \
           -alpha set -bordercolor none -border 3 \
           \( +clone -alpha transparent -background none \
              -fill white -stroke none -strokewidth 0 -draw @tmp.mvg \) \
           -compose DstIn -composite \
           \( +clone -alpha transparent -background none \
              -fill none -stroke black -strokewidth 3 -draw @tmp.mvg \
              -fill none -stroke white -strokewidth 1 -draw @tmp.mvg \) \
           -compose Over -composite $@
	rm -f tmp*

all: $(IMAGES)

clean:
	rm -f *-th.png
