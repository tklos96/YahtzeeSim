import matplotlib.pyplot as plt
import numpy as np


def chi_squared(n,k,expected,counts):
    expected_counts = n*expected
    var = np.square(counts-expected_counts)
    chi_sq = np.sum(var/expected_counts)
    return chi_sq

def plotMovingAverages():
    dataStd = np.loadtxt('log_standard.txt',delimiter=',',skiprows=3)
    nTrialsStd    = dataStd[:,0]
    winningsStd   = dataStd[:,3]
    avgPayoutStd  = winningsStd/nTrialsStd
    dataFun = np.loadtxt('log_fun.txt',delimiter=',',skiprows=3)
    nTrialsFun    = dataFun[:,0]
    winningsFun   = dataFun[:,3]
    avgPayoutFun  = winningsFun/nTrialsFun

    #Plot moving average payout for both variants
    fig,ax = plt.subplots()
    ax.hlines(y=3.12875614, xmin=1, xmax=nTrialsStd[-1],color='black',linestyle='--')
    ax.hlines(y=6.61214760, xmin=1, xmax=nTrialsFun[-1],color='black',linestyle='--')

    ax.plot(nTrialsStd,avgPayoutStd,label='Standard Yahtzee')
    ax.plot(nTrialsFun,avgPayoutFun,label='Fun Yahtzee')

    ax.set_title('Figure 3: Moving Average of Payout')
    ax.set_ylabel('Average Payout ($)')
    ax.set_xlabel('Number of trials')
    ax.legend(loc='lower right')

    plt.savefig('img/movingAverage.png')
    #plt.show()

def plotOutcomes():
    dataStd = np.loadtxt('log_standard.txt',delimiter=',',skiprows=3)
    outcomesStd   = dataStd[-1,1:3]
    freqStd       = outcomesStd/dataStd[-1,0]
    dataFun = np.loadtxt('log_fun.txt',delimiter=',',skiprows=3)
    outcomesFun   = dataFun[-1,1:3]
    freqFun       = outcomesFun/dataFun[-1,0]

    x_vals = np.array([0,1])
    x_labels = ['Yahtzee (5 6s)','Four-of-a-kind (4 6s)']

    fig,ax = plt.subplots()

    bs = ax.bar(x_vals,freqStd,0.25,label='Standard Yahtzee')
    bf = ax.bar(x_vals+0.25,freqFun,0.25,label='Fun Yahtzee')

    ax.set_xticks(x_vals+0.125,x_labels)
    ax.set_title('Figure 2: Frequency of Payout Outcomes')
    ax.set_ylabel('Frequency')
    ax.set_xlabel('Outcome')
    ax.legend(loc='upper left')
    ax.bar_label(bs, fmt='%.4f')
    ax.bar_label(bf, fmt='%.4f')

    plt.savefig('img/outcomeResults.png')
    #plt.show()

    trialsStd = dataStd[-1,0]
    outcomesStdFull = np.array( [outcomesStd[0], outcomesStd[1],
                                 trialsStd-np.sum(outcomesStd)] )
    exStd = np.array([0.013057, 0.091154, 0.895789])
    chiSqStd  = chi_squared(trialsStd,3,exStd,outcomesStdFull)
    trialsFun = dataFun[-1,0]
    outcomesFunFull = np.array( [outcomesFun[0], outcomesFun[1],
                                 trialsFun-np.sum(outcomesFun)] )
    exFun = np.array([0.031503, 0.173093, 0.795404])
    chiSqFun  = chi_squared(trialsFun,3,exFun,outcomesFunFull)
    print("Payout Outcomes results:")
    print("chi_squared for Standard Yahtzee = ",chiSqStd)
    print("chi_squared for FunYahtzee       = ",chiSqFun)


def plotDiceResults():
    dataStd = np.loadtxt('log_standard.txt',delimiter=',',skiprows=3)
    dataFun = np.loadtxt('log_fun.txt',delimiter=',',skiprows=3)

    #Get roll counts for both Standard and Fun
    rollCountsStd = dataStd[-1,4:10]
    rollCountsFun = dataFun[-1,4:10]

    #Calculate frequency of outcomes for both variants
    nStd = np.sum(rollCountsStd)
    nFun = np.sum(rollCountsFun)
    rollFreqStd   = rollCountsStd/nStd
    rollFreqFun   = rollCountsFun/nFun

    #Plot frequencies
    fig, ax = plt.subplots()
    x = np.array([i for i in range(1,7)])
    ax.bar(x,rollFreqStd,0.25,label='Standard Yahtzee')
    ax.bar(x+0.25,rollFreqFun,0.25,label='Fun Yahtzee')

    ax.set_xticks(x+0.125,x)
    ax.set_title('Figure 1: Frequency of Die Results')
    ax.set_ylabel('Frequency')
    ax.set_xlabel('Die result')
    ax.legend(loc='upper left')

    plt.savefig('img/dieResults.png')
    #plt.show()

    #Calculate Chi-squared metric for both distributions
    expected = np.array( [1.0/6.0 for _ in range(6)] )
    chiSqStd  = chi_squared(nStd,6,expected,rollCountsStd)
    chiSqFun = chi_squared(nFun,6,expected,rollCountsFun)
    print("Roll count results:")
    print("chi_squared for Standard Yahtzee = ",chiSqStd)
    print("chi_squared for FunYahtzee       = ",chiSqFun)


if __name__=='__main__':


    plotOutcomes()
    plotMovingAverages()
    plotDiceResults()
