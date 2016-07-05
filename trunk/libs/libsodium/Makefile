SRC_NAME=libsodium-1.0.10

#COPTS= -Os -pipe -mno-branch-likely -fno-caller-saves -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -msoft-float
#COPTS+= -I$(DESTDIR)/include
#
#LOPTS= -L$(DESTDIR)/lib

all: config_test
	$(MAKE) -C $(SRC_NAME)

config_test:
	( if [ -f ./config_done ]; then \
		echo "the same configuration"; \
	else \
		make configure && touch config_done; \
	fi )

configure:
	( cd $(SRC_NAME) ; \
	./configure \
		--disable-ssp \
		--prefix=/ \
		--host=$(HOST_TARGET) \
		--build=$(HOST_BUILD) \
		$(if $(CONFIG_LIBSODIUM_MINIMAL),--enable-minimal=yes,--enable-minimal=no) ; \
	)

clean:
	if [ -f $(SRC_NAME)/Makefile ] ; then \
		$(MAKE) -C $(SRC_NAME) distclean ; \
	fi ; \
	rm -f config_done

install:
	$(MAKE) -C $(SRC_NAME) install DESTDIR="$(STAGEDIR)"

romfs:
	cp -fP $(DESTDIR)/lib/libsodium.so* $(ROMFSDIR)/lib
#	cp -fP $(DESTDIR)/lib/libsodium.a $(ROMFSDIR)/lib
#	cp -fP $(DESTDIR)/lib/pkgconfig/libsodium.pc $(ROMFSDIR)/lib/pkgconfig
#	cp -fP $(DESTDIR)/include/sodium.h $(ROMFSDIR)/include
#	cp -fP $(DESTDIR)/include/sodium/*.h $(ROMFSDIR)/include/sodium
