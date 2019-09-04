import parse_tag
import gen_hookomp_h        as ghh
import gen_hookomp_c        as ghc
import gen_prepostdef       as gppd
import gen_prepostfunctions as gppf

tags = parse_tag.parse()
print('\n')

# generate the nexts files
path = './output/'
ghh.gen_hookomp_h(tags, path + 'hookomp.h')
ghc.gen_hookomp_c(tags, path + 'hookomp.c')
gppd.gen_prepostdef(tags, path + 'prepostdef.h')
gppf.gen_prepostfunctions(tags, path + 'prepostfunctions.c')