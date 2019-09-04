import parse_tag
import gen_hookomp_h        as ghh
import gen_hookomp_c        as ghc
import gen_prepostdef       as gppd
import gen_prepostfunctions as gppf

tags = parse_tag.parse()

# generate the nexts files
ghh.gen_hookomp_h(tags)
ghc.gen_hookomp_c(tags)
gppd.gen_prepostdef(tags)
gppf.gen_prepostfunctions(tags)