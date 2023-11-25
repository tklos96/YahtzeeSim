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
    ax.plot(nTrialsStd,avgPayoutStd,label='Standard Yahtzee')
    ax.plot(nTrialsFun,avgPayoutFun,label='Fun Yahtzee')

    ax.set_title('Moving Average of Payout')
    ax.set_ylabel('Average Payout ($)')
    ax.set_xlabel('Number of trials')
    ax.legend(loc='upper right')

    plt.savefig('movingAverage.png')
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

    ax.bar(x_vals,freqStd,0.25,label='Standard Yahtzee')
    ax.bar(x_vals+0.25,freqFun,0.25,label='Fun Yahtzee')

    ax.set_xticks(x_vals+0.125,x_labels)
    ax.set_title('Frequency of Payout Outcomes')
    ax.set_ylabel('Frequency')
    ax.set_xlabel('Outcome')
    ax.legend(loc='upper left')

    plt.savefig('outcomeResults.png')
    #plt.show()


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
    ax.set_title('Frequency of Die Results')
    ax.set_ylabel('Frequency')
    ax.set_xlabel('Die result')
    ax.legend(loc='upper left')

    plt.savefig('dieResults.png')
    #plt.show()

    #Calculate Chi-squared metric for both distributions
    expected = np.array( [1.0/6.0 for _ in range(6)] )
    chiSqStd  = chi_squared(nStd,6,expected,rollCountsStd)
    chiSqFun = chi_squared(nFun,6,expected,rollCountsFun)
    print("chi_squared for Standard Yahtzee = ",chiSqStd)
    print("chi_squared for FunYahtzee       = ",chiSqFun)


if __name__=='__main__':


    plotOutcomes()
    plotMovingAverages()
    plotDiceResults()
