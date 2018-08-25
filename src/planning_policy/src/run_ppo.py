#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
The class used to run the policy network trained using ppo
zhuoxu@berkeley.edu
"""


from config_ppo import Config_PPO
from ppo import PPO
import driving


class Run_PPO:
    def __init__(self, config):
        self.config = config
        self.env = driving.LaneKeeping()
        self.config.s_dim = self.env.getObservSpaceDim()
        self.config.a_dim = self.env.getActionSpaceDim()
        self.ppo = PPO(config=config)

    def restore(self, ckpt_name='model.ckpt'):
        self.ppo.saver.restore(self.ppo.sess, self.config.model_path + ckpt_name)
        print("expert model from " + self.config.model_path + ckpt_name + " restored.")

    def obs_to_dyn_act(self, obs):
        return self.ppo.choose_action(obs)

    def obs_to_kin_act(self, obs, dyn_act):
        return self.env.vehicle.simulateWithState(dyn_act, obs)


if __name__ == '__main__':
    config_ppo = Config_PPO(log_name='model')
    run_ppo = Run_PPO(config_ppo)