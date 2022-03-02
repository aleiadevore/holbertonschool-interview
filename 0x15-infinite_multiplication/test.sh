# Script that checks our multiplication function against
# the (bc) command line caluculater's results.
​
# Usage: ./meow_test.sh <(bc) result> <our result>
​
# Tests From BC:
​
# 66666 * 66666
# 4444355556
 
# meow * 0
# 0
 
# 46540654065406546540646540 * 450646540654065406540654
# 20973384754353025713849406815215785700981954437160
 
# 540650465406504165 * 0000000000000000000000000000000000000000000000000
# 0
 
# 406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100 * 406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100406749840980484980487487987879794321321065460132424100
# 16544543313764981883272851910560625919126922249306714094215295989449\
# 81716346307301883299275632465872469442817188604866513465244365329412\
# 71053595935223952000821422495568013408194877238435152353777264307201\
# 31675469856327227554016504323004033736343650093267917868150857570404\
# 89830669218915828422395745192246010511560462624528448256905936787399\
# 35644141785601948269423133411016329985436952687297938469613315477579\
# 06567860384155327713998543695268729793846961331547757906567860384155\
# 32771399854369526872979384696133154775790656786038415532771399854369\
# 52687297938469613315477579065678603841553277139985436952687297938469\
# 61331547757906567860384155327713998543695268729793846961331547757906\
# 56786038415532771399854369526872979384696133154775790656786038415532\
# 77139985436952687297938469613315477579065678603841553277139985436952\
# 68729793846961331547757906567860384155327713998543695268729793846961\
# 33154775790656786038415532771399854369526872979384696133154775790656\
# 78603841553277139985436952687297938469613315477579065678603841553277\
# 13998543695268729793846961331547757906567860384155327713998527150725\
# 41602886507805869584734594194125723307840728444947997274034402979786\
# 84747390735751040594966030195703718092200646591945176782536308012082\
# 66861760127631856294138467388974359237488032522528841429664023652244\
# 14221646771471328952395729781141425647459246628717685642813879696203\
# 76046886771075903059841077552685507014687140611262093619198533969173\
# 691977117409180708142260810000
 
# 56460465 * meow
# 0
 
# 1 * 1
# 1
 
# 65464050654 * 0000000000000000000000000000000000001
# 65464050654
 
# 0 * 6540888888888888886000000004
# 0
​
let expected=$1
let got=$2
if [ $expected -eq $got ]; then
    echo "OK"
else
    echo "FAIL"
fi