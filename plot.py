import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter,
                               AutoMinorLocator,LogLocator)

plt.rcParams['savefig.dpi'] = 1200
plt.rcParams["figure.dpi"] = 100
plt.rcParams['text.usetex'] = True 
plt.rcParams['mathtext.fontset'] = 'custom'
plt.rcParams['mathtext.rm'] = 'Bitstream Vera Sans'
plt.rcParams['mathtext.it'] = 'Bitstream Vera Sans:italic'
plt.rcParams['mathtext.bf'] = 'Bitstream Vera Sans:bold'
plt.rcParams['mathtext.fontset'] = 'stix'
plt.rcParams['font.family'] = 'STIXGeneral'
plt.rcParams['mathtext.fontset'] = 'cm'

data = np.loadtxt('data.dat')


fig, ax = plt.subplots(ncols=1)
plt.tick_params(direction='inout',which='major', length=11)

ax.plot(data[:,1],data[:,2],'o', markersize = 5, color='b', label=r'Strassen')
ax.plot(data[:,1],data[:,3],'o', markersize = 5, color='red', label=r'Linear')

ax.set_yscale('log')
ax.set_xscale('log')
ax.xaxis.set_minor_locator(AutoMinorLocator())
ax.yaxis.set_minor_locator(AutoMinorLocator())
ax.set_xlabel(r"Matrix size", fontsize='24')
ax.set_ylabel(r"CPU time", fontsize='24')
#ax.yaxis.set_ticks([0,-1000,-2000,-3000])
ax.xaxis.set_ticks([0e06,0.5e06,1e06,1.5e06,2e06])
plt.yticks(fontsize=24)
plt.xticks(fontsize=24)

secax = ax.secondary_xaxis('top')
secax.xaxis.set_ticklabels([])
secax.xaxis.set_minor_locator(AutoMinorLocator())
secax.tick_params(direction='inout',which='major', length=11)
secax.xaxis.set_ticks([0e06,0.5e06,1e06,1.5e06,2e06])
secay= ax.secondary_yaxis('right')
secay.yaxis.set_ticklabels([])
secay.yaxis.set_minor_locator(AutoMinorLocator())
#secay.yaxis.set_ticks([0,-1000,-2000,-3000])
secay.tick_params(direction='inout',which='major', length=11)


plt.legend(frameon=False,fontsize='24' )
plt.savefig('matrix_multi_log.pdf', format='pdf', bbox_inches='tight', facecolor='none')
plt.show();
